#include <bits/stdc++.h>
using namespace std;
vector<int> locations[100];
bool LEFT[300];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    int a;
    cin >> a;
    locations[a].push_back(i);
  }
  vector<int> useless;
  int l = 0, r = 0;
  for (int i = 10; i < 100; i++) {
    if (locations[i].size() == 1) {
      if (l < r) {
        LEFT[locations[i][0]] = true;
        l++;
      } else
        r++;
    } else if (locations[i].size() == 2) {
      l++;
      r++;
      LEFT[locations[i][0]] = true;
    } else if (locations[i].size() > 2) {
      l++;
      r++;
      LEFT[locations[i][0]] = true;
      for (int j = 2; j < locations[i].size(); j++) {
        useless.push_back(locations[i][j]);
      }
    }
  }
  cout << l * r << '\n';
  for (int i = 0; i < useless.size(); i++) {
    if (l < r) {
      l++;
      LEFT[useless[i]] = true;
    } else
      r++;
  }
  for (int i = 0; i < 2 * n; i++) {
    cout << LEFT[i] + 1;
    if (i != 2 * n - 1) cout << ' ';
  }
  cout << '\n';
}
