#include <bits/stdc++.h>
using namespace std;
const int maskMax = 1 << 18;
double m[19][19];
double t[19][maskMax + 5];
double solve(int atual, int mask) {
  int cnt = 0;
  int quem = 2;
  int maska = 0;
  for (int i = 1; i <= mask; i <<= 1) {
    if (i & mask) cnt++;
    if (quem == atual) maska = i;
    quem++;
  }
  if (cnt == 1) {
    return m[1][atual];
  }
  double &ret = t[atual][mask];
  if (ret != -1) return ret;
  int qual = 1;
  ret = 0;
  for (int i = 1; i <= mask; i <<= 1) {
    qual++;
    if (i == maska) continue;
    if (i & mask) {
      ret = max(ret, solve(atual, mask - i) * m[atual][qual] +
                         solve(qual, mask - maska) * m[qual][atual]);
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  for (int i = 0; i < 19; i++) {
    for (int j = 0; j < maskMax + 5; j++) {
      t[i][j] = -1;
    }
  }
  int n;
  cin >> n;
  cout << fixed << setprecision(16);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> m[i][j];
    }
  }
  if (n == 1) {
    cout << 100.000000 << endl;
    return 0;
  }
  double res = 0;
  int mask = 1 << (n - 1);
  mask--;
  for (int i = 2; i <= n; i++) {
    res = max(res, solve(i, mask));
  }
  cout << res << endl;
}
