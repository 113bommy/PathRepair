#include <bits/stdc++.h>
using namespace std;
int A[100666], B[100666], Nr[100666 * 2];
int fr1[100666], fr2[100666];
int bs(int value, int lmax) {
  int pos, step;
  for (step = 1; step <= lmax; step <<= 1)
    ;
  for (pos = 0; step; step >>= 1)
    if (pos + step <= lmax && Nr[pos + step] <= value) pos += step;
  return pos + step;
}
int main() {
  int n, m, k, i, tps = 1, nrel = 0;
  cin >> n >> m >> k;
  for (i = 1; i <= n; ++i) {
    cin >> A[i];
    Nr[++nrel] = A[i];
  }
  for (i = 1; i <= m; ++i) {
    cin >> B[i];
    Nr[++nrel] = B[i];
  }
  sort(Nr + 1, Nr + nrel + 1);
  for (i = 2; i <= nrel; ++i)
    if (Nr[i] != Nr[tps]) Nr[++tps] = Nr[i];
  for (i = 1; i <= n; ++i) ++fr1[bs(A[i], tps)];
  for (i = 1; i <= m; ++i) ++fr2[bs(B[i], tps)];
  int s1 = 0, s2 = 0;
  for (i = tps; i > 0; --i) {
    s1 += fr1[i];
    s2 += fr2[i];
    if (s1 > s2) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
