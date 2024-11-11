#include <bits/stdc++.h>
using namespace std;
void update(char *an, char *s, int n) {
  bool flag = 0;
  for (int i = 0; i < n; ++i)
    if (an[i] != s[i]) {
      if (an[i] > s[i]) flag = 1;
      break;
    }
  if (flag) {
    copy(s, s + n, an);
  }
}
void duval(char *s, int n, int *p, bool *f, int &m, bool type) {
  m = 0, p[0] = -1;
  int i = 0, j = 0, k = 1;
  bool flag = 0;
  while (i < n) {
    if (s[k] == s[j]) {
      ++j, ++k;
    } else if (s[k] > s[j]) {
      j = i, ++k;
    } else {
      int t = k - j;
      if (t == 1) {
        if (!flag || type) ++m;
        while (i <= j) {
          p[m] = i + t - 1;
          i += t;
        }
        flag = f[m] = 1;
      } else {
        ++m;
        while (i <= j) {
          p[m] = i + t - 1;
          i += t;
        }
        flag = f[m] = 0;
      }
      j = i, k = j + 1;
    }
  }
}
int nex[5000050];
int extend[5000050];
void getnext(char *T, int m) {
  nex[0] = m;
  while (nex[1] < m && T[nex[1]] == T[1 + nex[1]]) {
    ++nex[1];
  }
  int pos = 1, P = nex[1];
  for (int i = 2; i < m; ++i) {
    int len = nex[i - pos];
    if (i + len - 1 < P) {
      nex[i] = len;
    } else {
      nex[i] = max(0, P - i + 1);
      while (i + nex[i] < m && T[nex[i]] == T[i + nex[i]]) {
        ++nex[i];
      }
      pos = i, P = i + nex[i] - 1;
    }
  }
}
void exKMP(char *S, int n, char *T, int m) {
  getnext(T, m);
  while (extend[0] < m && extend[0] < n && S[extend[0]] == T[extend[0]]) {
    ++extend[0];
  }
  int pos = 0, P = extend[0] - 1;
  for (int i = 1; i < n; ++i) {
    int len = nex[i - pos];
    if (i + len - 1 < P) {
      extend[i] = len;
    } else {
      extend[i] = max(0, P - i + 1);
      while (extend[i] < m && i + extend[i] < n &&
             S[i + extend[i]] == T[extend[i]]) {
        ++extend[i];
      }
      pos = i, P = i + extend[i] - 1;
    }
  }
}
int p[5000050], m;
bool f[5000050];
void solve(char *s, char *sR, int n, char *an) {
  copy(s, s + n, an);
  exKMP(s, n, sR, n);
  int k = 0;
  for (int i = 1; i < n; ++i) {
    if (extend[k] < i - k) {
      if (sR[extend[k]] > s[k + extend[k]]) {
        k = i;
      }
    } else if (nex[i - k] < n - i) {
      if (sR[i - k + nex[i - k]] > sR[nex[i - k]]) {
        k = i;
      }
    }
  }
  reverse(s + k, s + n);
  update(an, s, n);
  reverse(s + k, s + n);
  duval(sR, n, p, f, m, 1);
  reverse(s, s + n - p[m - 1] - 1);
  update(an, s, n);
  reverse(s + n - p[m - 1] - 1, s + n);
  update(an, s, n);
  reverse(s + n - p[m - 1] - 1, s + n);
  reverse(s, s + n - p[m - 1] - 1);
  reverse(s, s + n - p[m - 2] - 1);
  update(an, s, n);
  reverse(s + n - p[m - 2] - 1, s + n);
  update(an, s, n);
}
int n, k;
char s[5000050];
char t[5000050];
char an[5000050];
char sR[5000050];
int main() {
  scanf("%s", s);
  scanf("%d", &k);
  n = strlen(s);
  copy(s, s + n, an);
  reverse_copy(s, s + n, sR);
  update(an, sR, n);
  if (k >= 2) {
    duval(sR, n, p, f, m, 0);
    if (m <= k) {
      for (int i = 1; i <= m; ++i) {
        if (!f[i]) reverse(s + n - p[i] - 1, s + n - p[i - 1] - 1);
      }
      update(an, s, n);
    } else {
      for (int i = 0; i < k - 2; ++i) {
        if (!f[m - i]) reverse(s + n - p[m - i] - 1, s + n - p[m - i - 1] - 1);
      }
      int l = p[m - (k - 2)] + 1;
      solve(s + n - l, sR, l, t);
      for (int i = 0; i < l; ++i) {
        s[n - l + i] = t[i];
      }
      update(an, s, n);
    }
  }
  printf("%s\n", an);
  return 0;
}
