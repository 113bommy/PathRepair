#include <bits/stdc++.h>
using namespace std;
const int Pri[25] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                     43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
const int Mod[4] = {300690390, 2044926619, 1808691197, 2073080791};
vector<int> f[17][4];
string ST;
long long a[100000];
int n, m, i, j, k, d, r[31], e, s[17], len, c;
bool V[25];
int Dp(int p) {
  int R = 0, W = 0;
  for (int i = 0; i < len; i++) R = R * (d + 1) + r[i];
  if (f[d][p][R] != -1) return f[d][p][R];
  f[d][p][R] = 1;
  for (int i = 0; i < len; i++)
    if (r[i] == d) {
      for (int j = 0; j < d; j++) {
        r[i] = j;
        f[d][p][R] = (long long)f[d][p][R] * Dp(p) % Mod[p];
      }
      r[i] = d;
      return f[d][p][R];
    }
  for (int i = 0; i < len; i++) W = W * d + r[i];
  if (W < n) f[d][p][R] = a[W] % Mod[p];
  return f[d][p][R];
}
void print() {
  for (int i = 0; i < 25; i++)
    if (V[i]) {
      printf("%d\n", Pri[i]);
      return;
    }
  puts("-1");
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 2; i < 17; i++) {
    e = 1, j = 0, k = 1;
    while (k < n) e *= (i + 1), k *= i, j++;
    s[i] = j;
    for (j = 0; j < 4; j++) f[i][j].resize(e, -1);
  }
  cin >> m;
  while (m--) {
    cin >> d >> ST >> c;
    len = s[d];
    for (i = 0; i < len; i++) {
      k = ST.length() - len + i;
      if (ST[k] == '?')
        r[i] = d;
      else if (ST[k] >= '0' && ST[k] <= '9')
        r[i] = ST[k] - '0';
      else
        r[i] = ST[k] - 'A' + 10;
      if (k < 0) r[i] = 0;
    }
    memset(V, 0, sizeof(V));
    for (i = 0; i < 4; i++) {
      int tmp = Dp(i);
      tmp = (tmp + c) % Mod[i];
      for (j = 0; j < 25; j++)
        if (Mod[i] % Pri[j] == 0 && tmp % Pri[j] == 0) V[j] = 1;
    }
    print();
  }
  return 0;
}
