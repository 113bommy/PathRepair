#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
char sir[MAXN];
int n, q, sum1[MAXN], sum2[MAXN], sum3[MAXN];
int abs(int a) {
  if (a < 0) return -a;
  return a;
}
int main() {
  cin.getline(sir + 1, MAXN);
  n = strlen(sir + 1);
  for (int i = 1; i <= n; ++i) {
    sum1[i] = sum1[i - 1];
    sum2[i] = sum2[i - 1];
    sum3[i] = sum3[i - 1];
    switch (sir[i]) {
      case 'x':
        ++sum1[i];
        break;
      case 'y':
        ++sum2[i];
        break;
      case 'z':
        ++sum3[i];
        break;
    }
  }
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    int l, r;
    cin >> l >> r;
    int nr1 = sum1[r] - sum1[l - 1];
    int nr2 = sum2[r] - sum2[l - 1];
    int nr3 = sum3[r] - sum3[l - 1];
    int minim = min(nr1, min(nr2, nr3));
    int maxim = max(nr1, max(nr2, nr3));
    if (l - r + 1 < 3) {
      cout << "YES\n";
      continue;
    }
    if (abs(maxim - minim) > 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
