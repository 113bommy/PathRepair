#include <bits/stdc++.h>
using namespace std;
char t[101][101], t1[101][101];
int n, k, sum = 1e9;
int I_T(char x[101]) {
  int a = 0, q = 1, w = k - 1;
  while (w >= 0) {
    a += (x[w] - '0') * q;
    q *= 10;
    --w;
  }
  return a;
}
int a[101];
int main() {
  cin >> n >> k;
  for (int i = 0; i < (n); i++) {
    string s;
    cin >> s;
    for (int j = (k - 1); j >= (0); j--) t[i][j] = s[j];
  }
  for (int i = 0; i < (k); i++) a[i] = i;
  do {
    for (int i = 0; i < (n); i++)
      for (int j = 0; j < (k); j++) t1[i][j] = t[i][a[j]];
    int mn = 1e9, mx = -1e9;
    for (int i = 0; i < (n); i++) {
      if (I_T(t1[i]) < mn) mn = I_T(t1[i]);
      if (I_T(t1[i]) > mx) mx = I_T(t1[i]);
    }
    sum = min(sum, mx - mn);
  } while (next_permutation(a, a + k));
  cout << sum;
  return 0;
}
