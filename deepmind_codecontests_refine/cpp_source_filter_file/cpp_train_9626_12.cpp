#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> f, s;
  int n, m, x;
  long long mx, my, sumx, sumy;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    f.push_back(x);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x;
    s.push_back(x);
  }
  mx = sumx = 2 * n;
  my = sumy = 2 * m;
  sort(f.begin(), f.end());
  sort(s.begin(), s.end());
  int i = n - 1, j = m - 1;
  while (i >= 0) {
    int tmp = f[i];
    while (f[i] == tmp && i >= 0) {
      sumx += 1;
      i--;
    }
    while (s[j] >= tmp && j >= 0) {
      sumy += 1;
      j--;
    }
    if (sumx - sumy > mx - my) {
      mx = sumx;
      my = sumy;
    }
  }
  cout << mx << ":" << my;
  return 0;
}
