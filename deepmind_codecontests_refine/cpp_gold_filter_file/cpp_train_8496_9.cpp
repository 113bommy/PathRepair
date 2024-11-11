#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> inp(n);
  for (int i = 0; i < n; i++) {
    cin >> inp[i].first;
    cin >> inp[i].second;
  }
  int visited = inp[0].first;
  for (int i = 1; i < n; i++) {
    int x = inp[i].first;
    int y = inp[i].second;
    while (visited >= x) {
      x = x + y;
    }
    visited = x;
  }
  cout << visited << endl;
  return 0;
}
