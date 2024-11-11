#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  unordered_map<int, vector<int>> places;
  vector<vector<int>> vv(n + 1, vector<int>());
  int current = 0;
  for (int i = 1; i <= n - 2; ++i) {
    for (int j = 1; j <= 3; ++j) {
      int a;
      cin >> a;
      places[a].push_back(i);
      vv[i].push_back(a);
    }
  }
  vector<bool> processed(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (places[i].size() == 1) {
      current = i;
    }
  }
  processed[current] = true;
  cout << current << " ";
  int triple = places[current][0];
  for (int v : vv[triple]) {
    if (places[v].size() == 2) {
      current = v;
    }
  }
  processed[current] = true;
  cout << current << " ";
  for (int i = 3; i <= n - 2; ++i) {
    for (int ind : places[current]) {
      int foreign = 0;
      for (int v : vv[ind]) {
        foreign += !processed[v];
      }
      if (foreign == 1) {
        for (int v : vv[ind]) {
          if (!processed[v]) {
            current = v;
          }
        }
      }
    }
    processed[current] = true;
    cout << current << " ";
  }
  for (int i = 1; i <= n; ++i) {
    if (!processed[i] && places[i].size() == 2) {
      cout << i << " ";
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!processed[i] && places[i].size() == 1) {
      cout << i << " ";
    }
  }
}
