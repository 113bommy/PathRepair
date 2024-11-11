#include <bits/stdc++.h>
#pragma comment(linker, "/stack:64000000")
using namespace std;
template <typename first>
inline first abs(const first& a) {
  return a < 0 ? -a : a;
}
template <typename first>
inline first sqr(const first& a) {
  return a * a;
}
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;
const int N = 100 * 1000 + 13;
const int K = 500 + 13;
int n;
char s[N];
int k, L, R;
int c[K], lf[K], rg[K];
vector<int> occ[26 + 3];
int cntGood, okRules[N];
int ptr[26];
void dec(char c, int rg) {
  if (ptr[int(c)] < rg) return;
  int lfidx = (ptr[int(c)] - rg - 1 >= 0 ? occ[c][ptr[int(c)] - rg - 1] : -1);
  int rgidx = occ[c][ptr[int(c)] - rg] - (rg == 0);
  for (int i = lfidx + 1; i <= rgidx; i++) {
    okRules[i]--;
    if (okRules[i] == R)
      cntGood++;
    else if (okRules[i] == L - 1)
      cntGood--;
  }
}
void inc(char c, int lf) {
  if (lf == 0) return;
  if (ptr[int(c)] + 1 < lf) return;
  int lfidx = (ptr[int(c)] - lf >= 0 ? occ[c][ptr[int(c)] - lf] : -1);
  int rgidx = occ[c][ptr[int(c)] - lf + 1] - (lf == 1);
  for (int i = lfidx + 1; i <= rgidx; i++) {
    okRules[i]++;
    if (okRules[i] == L)
      cntGood++;
    else if (okRules[i] == R + 1)
      cntGood--;
  }
}
int main() {
  gets(s);
  n = strlen(s);
  for (int i = 0; i < int(n); i++) s[i] -= 'a';
  for (int i = 0; i < int(n); i++) occ[int(s[i])].push_back(i);
  scanf("%d %d %d\n", &k, &L, &R);
  for (int i = 0; i < int(k); i++)
    scanf("%c %d %d\n", &c[i], &lf[i], &rg[i]), c[i] -= 'a';
  long long ans = 0;
  memset(ptr, -1, sizeof(ptr));
  for (int i = 0; i < int(n); i++) {
    char curc = s[i];
    ptr[int(curc)]++;
    for (int j = 0; j < int(k); j++)
      if ((curc == c[j] && lf[j] <= 1 && 1 <= rg[j]) ||
          (curc != c[j] && lf[j] == 0))
        okRules[i]++;
    if (L <= okRules[i] && okRules[i] <= R) cntGood++;
    for (int j = 0; j < int(k); j++) {
      if (curc != c[j]) continue;
      inc(curc, lf[j]);
      dec(curc, rg[j]);
    }
    ans += cntGood;
  }
  cout << ans << endl;
  return 0;
}
