#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  map<int, bool> hb, hg;
  int b, g;
  cin >> b;
  for (int i = 0; i < b; i++) {
    int x;
    cin >> x;
    hb[x] = true;
  }
  cin >> g;
  for (int i = 0; i < g; i++) {
    int x;
    cin >> x;
    hg[x] = true;
  }
  for (int i = 0; i < 500; i++) {
    int by = i % n;
    int gi = i % m;
    if (hb[by] or hg[gi]) {
      hb[by] = true;
      hg[gi] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!hb[i]) {
      cout << "No";
      return 0;
    }
  }
  for (int i = 0; i < m; i++) {
    if (!hg[i]) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
