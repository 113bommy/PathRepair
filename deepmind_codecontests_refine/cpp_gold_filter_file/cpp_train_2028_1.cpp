#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long double EPS = 1e-8;
const int MAXN = 1e6 + 100;
const int MAXA = 10;
char s[MAXN];
int b[MAXN];
int cnt[MAXN];
int pos[MAXN];
int c[MAXN];
int tp[MAXN], tc[MAXN];
int pb[MAXN], sb[MAXN];
bool good[MAXN];
char brc(char c) {
  if (c == 0)
    return '(';
  else
    return ')';
}
void print(int st, int n) {
  for (int i = st; i < n; ++i) {
    printf("%c", brc(s[i]));
  }
  for (int i = 0; i < st; ++i) {
    printf("%c", brc(s[i]));
  }
}
int main() {
  scanf("%s", s);
  int n = strlen(s);
  b[0] = 0;
  for (int i = 0; i < (n); ++i) {
    if (s[i] == '(')
      s[i] = 0;
    else
      s[i] = 1;
  }
  for (int i = 0; i < (n); ++i) {
    if (s[i] == 0)
      b[i + 1] = b[i] + 1;
    else
      b[i + 1] = b[i] - 1;
  }
  int sum = b[n];
  for (int i = 0; i < (n); ++i) {
    cnt[s[i]]++;
  }
  cnt[1] += cnt[0];
  for (int i = n - 1; i >= 0; --i) {
    pos[--cnt[s[i]]] = i;
  }
  int cl = 0;
  c[pos[0]] = 0;
  for (int i = 1; i < n; ++i) {
    if (s[pos[i]] != s[pos[i - 1]]) cl++;
    c[pos[i]] = cl;
  }
  cl++;
  for (int lp = 0; (1 << lp) < n; ++lp) {
    for (int i = 0; i < (n); ++i) {
      tp[i] = (pos[i] - (1 << lp) + n) % n;
    }
    for (int i = 0; i < (cl); ++i) cnt[i] = 0;
    for (int i = 0; i < (n); ++i) {
      cnt[c[tp[i]]]++;
    }
    for (int i = 0; i < (cl - 1); ++i) {
      cnt[i + 1] += cnt[i];
    }
    for (int i = n - 1; i >= 0; --i) {
      pos[--cnt[c[tp[i]]]] = tp[i];
    }
    tc[pos[0]] = 0;
    cl = 0;
    for (int i = 1; i < n; ++i) {
      int m1 = (pos[i] + (1 << lp)) % n;
      int m2 = (pos[i - 1] + (1 << lp)) % n;
      if (c[pos[i]] != c[pos[i - 1]] || c[m1] != c[m2]) cl++;
      tc[pos[i]] = cl;
    }
    cl++;
    for (int i = 0; i < (n); ++i) {
      c[i] = tc[i];
    }
  }
  int mb = 0;
  for (int i = 0; i < (n + 1); ++i) {
    mb = min(mb, b[i]);
  }
  pb[0] = 0;
  for (int i = 1; i <= n; ++i) {
    pb[i] = min(pb[i - 1], b[i]);
  }
  sb[0] = b[n];
  for (int i = 1; i <= n; ++i) {
    sb[i] = min(sb[i - 1], b[n - i]);
  }
  int ans = 0;
  if (sum >= 0) {
    for (int i = 0; i < (n); ++i) {
      if (sb[n - i] >= b[i] && pb[i] + sum - b[i] >= 0) good[i] = true;
    }
    for (int i = 0; i < (n); ++i) {
      if (good[pos[i]]) {
        ans = pos[i];
        break;
      }
    }
    print(ans, n);
    for (int i = 0; i < (sum); ++i) {
      printf(")");
    }
  } else {
    for (int i = 0; i < (n); ++i) {
      if (sb[n - i] - b[i] - sum >= 0 && pb[i] - b[i] >= 0) good[i] = true;
    }
    for (int i = 0; i < (n); ++i) {
      if (good[pos[i]]) {
        ans = pos[i];
        break;
      }
    }
    for (int i = 0; i < (abs(sum)); ++i) {
      printf("(");
    }
    print(ans, n);
  }
  printf("\n");
  return 0;
}
