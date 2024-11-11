#include <bits/stdc++.h>
template <typename A, typename B>
inline void amax(A &x, B y) {
  if (x < y) x = y;
}
template <typename A, typename B>
inline void amin(A &x, B y) {
  if (!(x < y)) x = y;
}
using namespace std;
int n, k;
map<string, double> dp[10];
int A[10], _A[10];
int sana(string s) {
  int ret = 0;
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++) ret += (s[i] < s[j]);
  return ret;
}
string cevir() {
  string ret = "";
  for (int i = 0; i < n; i++) ret += A[i] + '0';
  return ret;
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", A + i);
    A[i]--;
    _A[i] = A[i];
  }
  double dwn = n * (n + 1) / 2;
  dwn = 1.0 / dwn;
  string s = "", tmp;
  for (int i = 0; i < n; i++) s += ('0' + A[i]);
  dp[0][s] = 1.0;
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < n; j++) A[j] = j;
    do {
      tmp = cevir();
      for (int u1 = 0; u1 < n; u1++)
        for (int u2 = u1; u2 < n; u2++) {
          reverse(A + u1, A + u2 + 1);
          s = cevir();
          reverse(A + u1, A + u2 + 1);
          dp[i][s] += dp[i - 1][tmp] * dwn;
        }
    } while (next_permutation(A, A + n));
  }
  for (int i = 0; i < n; i++) A[i] = i;
  double ans = 0;
  do {
    s = cevir();
    ans += dp[k][s] * sana(s);
  } while (next_permutation(A, A + n));
  printf("%.12lf", ans);
}
