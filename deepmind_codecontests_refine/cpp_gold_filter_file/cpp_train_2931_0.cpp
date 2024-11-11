#include <bits/stdc++.h>
using namespace std;
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
vector<int> adj[300010];
vector<int> par(300010, -1);
vector<int> vis(300010, 0);
vector<int> dis(300010, 0);
int ask(vector<int> v1, vector<int> v2) {
  cout << v1.size() << " " << v2.size() << " ";
  for (auto i : v1) {
    cout << i << " ";
  }
  for (auto i : v2) {
    cout << i << " ";
  }
  cout << '\n';
  cout << flush;
  int num;
  cin >> num;
  return num;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v1, v2;
    v1.push_back(1);
    for (int i = 2; i <= n; i++) {
      v2.push_back(i);
    }
    int num;
    num = ask(v1, v2);
    int lo = 0, hi = (int)v2.size();
    int ans = v2[0];
    while (hi - lo > 1) {
      int mid = (lo + hi) / 2;
      vector<int> aux;
      for (int i = lo; i < mid; i++) {
        aux.push_back(v2[i]);
      }
      if (ask(v1, aux) == num) {
        hi = mid;
      } else {
        lo = mid;
      }
      ans = v2[lo];
    }
    int ax = ans;
    v1.clear();
    v1.push_back(ax);
    v2.clear();
    for (int i = 1; i <= n; i++) {
      if (i != ax) {
        v2.push_back(i);
      }
    }
    int num1 = ask(v1, v2);
    cout << -1 << " " << num1 << '\n';
    cout << flush;
  }
}
