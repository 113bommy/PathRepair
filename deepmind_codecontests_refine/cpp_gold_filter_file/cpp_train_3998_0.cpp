#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  int i, j;
  for (i = 0; i < n; i++) {
    pair<int, int> s;
    int d;
    cin >> d;
    s.first = d;
    s.second = i + 1;
    a.push_back(s);
  }
  int k = 0;
  int h = 0;
  int l, u;
  sort(a.begin(), a.end());
  for (i = 2; i < n; i++) {
    l = 0;
    u = i - 1;
    while (l < u) {
      int z = a[l].first + a[u].first;
      if (z == a[i].first) {
        k = a[i].second;
        l = a[l].second;
        u = a[u].second;
        h = 1;
        break;
      } else if (z > a[i].first) {
        u--;
      } else if (z < a[i].first) {
        l++;
      }
    }
    if (h == 1) {
      break;
    }
  }
  if (h == 1) {
    cout << k << " " << u << " " << l;
  } else {
    cout << "-1";
  }
}
