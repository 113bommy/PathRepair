#include <bits/stdc++.h>
using namespace std;
char a[150050];
char b[150050];
int c[150050][2];
int n;
int cnt1[28], cnt2[28], cnt3[28];
int pick1[28][150000], pick2[28][150000];
int main() {
  scanf("%d %s %s", &n, a, b);
  for (int i = 0; i < n; i++) {
    if (a[i] == '?') {
      pick1[0][cnt1[0]] = i;
      cnt1[0]++;
    } else {
      pick1[a[i] - 'a' + 1][cnt1[a[i] - 'a' + 1]] = i;
      cnt1[a[i] - 'a' + 1]++;
    }
    if (b[i] == '?') {
      pick2[0][cnt2[0]] = i;
      cnt2[0]++;
    } else {
      pick2[b[i] - 'a' + 1][cnt2[b[i] - 'a' + 1]] = i;
      cnt2[b[i] - 'a' + 1]++;
    }
  }
  for (int i = 1; i < 27; i++) {
    cnt3[i] = min(cnt1[i], cnt2[i]);
  }
  int itt = 0;
  for (int i = 1; i < 27; i++) {
    for (int j = 0; j < cnt3[i]; j++) {
      c[itt][0] = pick1[i][j];
      a[pick1[i][j]] = '*';
      c[itt][1] = pick2[i][j];
      b[pick2[i][j]] = '*';
      itt++;
    }
  }
  int itt2 = 0;
  for (int i = 0; i < cnt1[0]; i++) {
    if (itt2 == n) {
      int i1 = 0, i2 = 0;
      for (;;) {
        if (a[i1] == '*') {
          i1++;
          continue;
        }
        if (a[i2] == '*') {
          i2++;
          continue;
        }
        c[itt][0] = i1;
        a[i1] = '*';
        b[i2] = '*';
        c[itt][1] = i2;
        itt++;
        if (itt == n) break;
      }
      break;
    }
    if (b[itt2] != '?' && b[itt2] != '*') {
      c[itt][0] = pick1[0][i];
      a[pick1[0][i]] = '*';
      c[itt][1] = itt2;
      b[itt2] = '*';
      itt++;
    } else {
      itt2++;
      i--;
      continue;
    }
  }
  int itt1 = 0;
  for (int i = 0; i < cnt2[0]; i++) {
    if (a[itt1] != '?' && a[itt1] != '*') {
      if (b[pick2[0][i]] == '*') break;
      c[itt][0] = itt1;
      a[itt1] = '*';
      c[itt][1] = pick2[0][i];
      b[pick2[0][i]] = '*';
      itt++;
    } else {
      itt1++;
      i--;
      continue;
    }
  }
  printf("%d\n", itt);
  for (int i = 0; i < itt; i++) {
    printf("%d %d\n", c[i][0] + 1, c[i][1] + 1);
  }
  return 0;
}
