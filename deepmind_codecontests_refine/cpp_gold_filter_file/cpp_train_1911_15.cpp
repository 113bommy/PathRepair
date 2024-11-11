#include <bits/stdc++.h>
using namespace std;
const double LOG = log(2);
int m, n, j, k, l, i, o, p, __t, Dec[600000], Could[600000];
int Step[600000][23], Small[600000][23], Bound[600000][23];
char ch;
void read(int &a) {
  for (ch = getchar(); (ch < '0' || ch > '9') && (ch != '-'); ch = getchar())
    ;
  if (ch == '-')
    a = 0, __t = -1;
  else
    a = ch - '0', __t = 1;
  for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
    a = a * 10 + ch - '0';
  a *= __t;
}
inline int cmp(int a, int b) { return (Could[a] < Could[b]) ? (a) : (b); }
int Query(int L, int R) {
  int e = log(R - L + 1) / LOG;
  return cmp(Step[L][e], Step[R - (1 << (e)) + 1][e]);
}
int main() {
  read(m);
  for (int i = (1); i <= (m); i++) read(Dec[i]), Dec[m + i] = Dec[i];
  n = 2 * m;
  for (int i = (1); i <= (n); i++) {
    Step[i][0] = i;
    Could[i] = max(1, i - Dec[i]);
  }
  for (int i = 1, j = 2; j <= n; j <<= 1, i++)
    for (int k = 1; k + j - 1 <= n; k++)
      Step[k][i] = cmp(Step[k][i - 1], Step[k + (1 << (i - 1))][i - 1]);
  for (int i = (1); i <= (n); i++) {
    Small[i][0] = Query(Could[i], i);
    Bound[i][0] = Could[i];
    for (int j = 1;; j++) {
      Small[i][j] = Small[Small[i][j - 1]][j - 1];
      Bound[i][j] = Bound[Small[i][j - 1]][j - 1];
      if (Bound[i][j] == 1) break;
    }
  }
  long long Ans = 0;
  for (int i = (m); i <= (n - 1); i++) {
    long long ret = 0;
    int N = i, aim = i - m + 1;
    for (int j = (21); j >= (0); j--)
      if (Bound[N][j] != 0) {
        if (Bound[N][j] > aim) N = Small[N][j], ret += (1 << j);
      }
    Ans += ret + 1LL;
  }
  printf("%I64d\n", Ans);
}
