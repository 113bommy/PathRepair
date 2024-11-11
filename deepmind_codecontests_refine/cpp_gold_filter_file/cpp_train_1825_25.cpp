#include <bits/stdc++.h>
using namespace std;
long long kol1, l, tekres, ee, kol, r, n, k, p, e, c, a, b, f;
string m[300000], m1[300000];
long long t[300000], has[300000], has1[300000];
const long long md = 1000000007;
pair<long long, char> m3[300000];
int main() {
  scanf("%d%d", &n, &k);
  kol = 0;
  for (int i = 1; i <= n; i++) {
    char ch;
    scanf("%d%c%c", &a, &ch, &ch);
    if (m3[kol].second == ch)
      m3[kol].first += a;
    else {
      kol++;
      m3[kol].first = a;
      m3[kol].second = ch;
    }
  }
  for (int i = 1; i <= kol; i++) m[i] = to_string(m3[i].first) + m3[i].second;
  kol1 = 0;
  for (int i = 1; i <= k; i++) {
    char ch;
    scanf("%d%c%c", &a, &ch, &ch);
    if (m3[kol1].second == ch)
      m3[kol1].first += a;
    else {
      kol1++;
      m3[kol1].first = a;
      m3[kol1].second = ch;
    }
  }
  for (int i = 1; i <= kol1; i++) m1[i] = to_string(m3[i].first) + m3[i].second;
  if (kol < kol1) {
    printf("0");
    return 0;
  }
  t[0] = 1;
  for (int i = 1; i <= kol; i++) t[i] = (t[i - 1] * 293) % md;
  for (int i = 1; i <= kol; i++) {
    long long a = 0;
    for (int z = 0; z < m[i].length(); z++) a = (a + m[i][z] * t[z]) % md;
    has[i] = (has[i - 1] + a * t[i]) % md;
  }
  for (int i = 1; i <= kol1; i++) {
    long long a = 0;
    for (int z = 0; z < m1[i].length(); z++) a = (a + m1[i][z] * t[z]) % md;
    has1[i] = (has1[i - 1] + a * t[i]) % md;
  }
  long long res = 0;
  if (kol1 == 1) {
    for (int i = 1; i <= kol; i++)
      if (m[i][m[i].length() - 1] == m1[1][m1[1].length() - 1])
        res += max((long long)0,
                   stoll(m[i].substr(0, m[i].length() - 1).c_str()) -
                       stoll(m1[1].substr(0, m1[1].length() - 1).c_str()) + 1);
    printf("%I64d", res);
    return 0;
  }
  long long b1 = ((has1[kol1 - 1] + md - has1[1]) * t[kol - (kol1 - 1)]) % md;
  for (int i = 1; i <= kol - kol1 + 1; i++) {
    if (m[i][m[i].length() - 1] != m1[1][m1[1].length() - 1]) continue;
    long long a = stoll(m[i].substr(0, m[i].length() - 1).c_str());
    long long b = stoll(m1[1].substr(0, m1[1].length() - 1).c_str());
    if (a - b + 1 < 1) continue;
    if (kol1 > 2) {
      long long a1 =
          ((has[i + kol1 - 2] + md - has[i]) * t[kol - (i + kol1 - 2)]) % md;
      if (a1 != b1) continue;
    }
    if (m[i + kol1 - 1][m[i + kol1 - 1].length() - 1] !=
        m1[kol1][m1[kol1].length() - 1])
      continue;
    a = stoll(m[i + kol1 - 1].substr(0, m[i + kol1 - 1].length() - 1).c_str());
    b = stoll(m1[kol1].substr(0, m1[kol1].length() - 1).c_str());
    if (a - b + 1 < 1) continue;
    res++;
  }
  printf("%I64d", res);
  return 0;
}
