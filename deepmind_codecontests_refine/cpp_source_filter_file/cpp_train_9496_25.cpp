#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int N;
char res[102];
vector<string> g[102];
int cnt[102][26];
int r[26];
int tmp[26];
int q[51][2];
int m;
int a[100000];
int b[100000];
int v1[100000];
int v2[100000];
int f[51][2];
int lf[51][2];
int rg[51][2];
void query(int a, int b) {
  int i, k;
  int len;
  int n;
  int m;
  char buf[102];
  printf("? %d %d\n", a + 1, b + 1);
  fflush(stdout);
  n = (b - a + 1) * (b - a + 2) / 2;
  for (i = (0); i < (N + 1); i++) {
    g[i].clear();
  }
  for (i = (0); i < (N + 1); i++) {
    int j;
    for (j = (0); j < (26); j++) {
      cnt[i][j] = 0;
    }
  }
  for (i = (0); i < (n); i++) {
    int j;
    scanf("%s", buf);
    len = strlen(buf);
    g[len].push_back((string)buf);
    for (j = (0); j < (len); j++) {
      cnt[len][buf[j] - 'a']++;
    }
  }
  n = b - a + 1;
  for (k = (0); k < (26); k++) {
    r[k] = cnt[0][k];
  }
  for (i = (0); i < ((n + 1) / 2); i++) {
    q[i][0] = q[i][1] = -1;
    if (i == (n + 1) / 2 - 1) {
      for (k = (0); k < (26); k++) {
        r[k] = cnt[1][k];
      }
    } else {
      for (k = (0); k < (26); k++) {
        r[k] = cnt[1][k] - (cnt[i + 2][k] - cnt[i + 1][k]);
      }
    }
    for (k = (0); k < (i); k++) {
      for (m = (0); m < (2); m++) {
        if (q[k][m] >= 0) {
          r[q[k][m]]--;
        }
      }
    }
    m = 0;
    for (k = (0); k < (26); k++) {
      while (r[k]) {
        q[i][m++] = k;
        r[k]--;
      }
    }
  }
}
void answer(void) {
  printf("! %s\n", res);
  fflush(stdout);
  exit(0);
}
int main() {
  int i;
  int v;
  int odN;
  int lsz;
  int rsz;
  scanf("%d", &N);
  if (N <= 3) {
    int i;
    for (i = (0); i < (N); i++) {
      query(i, i);
      res[i] = g[1][0][0];
    }
    answer();
  }
  if (N % 2 == 0) {
    odN = N - 1;
  } else {
    odN = N;
  }
  lsz = (N + 1) / 2;
  rsz = (N + 2) / 2;
  for (i = (0); i < (N); i++) {
    res[i] = 127;
  }
  query(0, odN - 1);
  for (i = (0); i < ((odN + 1) / 2); i++) {
    if (q[i][1] == -1) {
      res[i] = q[i][0];
      continue;
    }
    a[m] = i;
    b[m] = odN - 1 - i;
    v1[m] = q[i][0];
    v2[m] = q[i][1];
    m++;
  }
  query(0, lsz - 1);
  for (i = (0); i < ((lsz + 1) / 2); i++) {
    if (q[i][1] == -1) {
      res[i] = q[i][0];
      continue;
    }
    a[m] = i;
    b[m] = lsz - 1 - i;
    v1[m] = q[i][0];
    v2[m] = q[i][1];
    m++;
  }
  query(N - rsz, N - 1);
  for (i = (0); i < ((rsz + 1) / 2); i++) {
    if (q[i][1] == -1) {
      res[N - rsz + i] = q[i][0];
      continue;
    }
    a[m] = N - rsz + i;
    b[m] = N - 1 - i;
    v1[m] = q[i][0];
    v2[m] = q[i][1];
    m++;
  }
  for (;;) {
    int fg = 0;
    for (i = (0); i < (m); i++) {
      if (res[a[i]] != 127 && res[b[i]] == 127) {
        res[b[i]] = ((int)res[a[i]]) ^ v1[i] ^ v2[i];
        fg++;
      }
      if (res[a[i]] == 127 && res[b[i]] != 127) {
        res[a[i]] = ((int)res[b[i]]) ^ v1[i] ^ v2[i];
        fg++;
      }
    }
    if (!fg) {
      break;
    }
  }
  for (i = (0); i < (N); i++) {
    res[i] += 'a';
  }
  answer();
  return 0;
}
