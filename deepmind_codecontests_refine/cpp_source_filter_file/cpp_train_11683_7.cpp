#include <bits/stdc++.h>
using namespace std;
int n, t;
int p[1000005], r[1000005], h[1000005];
string s;
void fix_index(int *b, int *e) {
  int pkm1, pk, np, i, d, m;
  pkm1 = p[*b + t];
  m = e - b;
  d = 0;
  np = b - r;
  for (i = 0; i < m; i++) {
    if (((pk = p[*b + t]) != pkm1) && !(np <= pkm1 && pk < np + m)) {
      pkm1 = pk;
      d = i;
    }
    p[*(b++)] = np + d;
  }
}
bool comp(int i, int j) { return p[i + t] < p[j + t]; }
void suff_arr() {
  int i, j, bc[256];
  t = 1;
  for (i = 0; i < 256; i++) bc[i] = 0;
  for (i = 0; i < n; i++) ++bc[int(s[i])];
  for (i = 1; i < 256; i++) bc[i] += bc[i - 1];
  for (i = 0; i < n; i++) r[--bc[int(s[i])]] = i;
  for (i = n - 1; i >= 0; i--) p[i] = bc[int(s[i])];
  for (t = 1; t < n; t *= 2) {
    for (i = 0, j = 1; i < n; i = j++) {
      while (j < n && p[r[j]] == p[r[i]]) ++j;
      if (j - i > 1) {
        sort(r + i, r + j, comp);
        fix_index(r + i, r + j);
      }
    }
  }
}
void lcp() {
  int tam = 0, i, j;
  for (i = 0; i < n; i++)
    if (p[i] > 0) {
      j = r[p[i] - 1];
      while (s[i + tam] == s[j + tam]) ++tam;
      h[p[i] - 1] = tam;
      if (tam > 0) --tam;
    }
  h[n - 1] = 0;
}
int k;
long long qnts[26];
int main(void) {
  cin >> s >> k;
  s += '$';
  n = s.size();
  suff_arr();
  int ini = 1, fim = n - 1;
  int dig = 0;
  string ans = "";
  if ((long long)((long long)(n) * (long long)(n - 1)) / 2 < k) {
    printf("No such line\n");
    return 0;
  }
  while (1) {
    memset(qnts, 0, sizeof qnts);
    for (int i = ini; i < fim + 1; i++)
      if (r[i] + dig < n - 1) {
        qnts[s[r[i] + dig] - 'a'] += (n - (r[i] + dig) - 1);
      }
    int letra = 0;
    for (int i = 0; i < 26; i++) {
      if (qnts[i] < k) {
        k -= qnts[i];
      } else {
        letra = i;
        break;
      }
    }
    ans += letra + 'a';
    int c = -1, t = -1;
    for (int i = ini; i < fim + 1; i++)
      if (r[i] + dig < n) {
        if (s[r[i] + dig] - 'a' == letra) {
          if (c == -1) c = i;
          t = i;
        }
      }
    ini = c, fim = t;
    if (fim - ini + 1 >= k)
      break;
    else
      k -= (fim - ini + 1);
    dig++;
  }
  cout << ans << endl;
  return 0;
}
