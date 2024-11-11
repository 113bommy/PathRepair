#include <bits/stdc++.h>
using namespace std;
const int MN = 1000001;
int n, m;
char str[MN];
char sub[MN];
int cnt[10];
char ans[MN];
char bans[MN];
void cp() {
  for (int i = 0; i <= n; ++i) {
    bans[i] = ans[i];
  }
}
void cpmin() {
  for (int i = 0; i < n; ++i) {
    if (bans[i] == ans[i])
      continue;
    else if (bans[i] < ans[i])
      break;
    else if (bans[i] > ans[i]) {
      cp();
      break;
    }
  }
}
void ins(int c) {
  for (int i = 0; i < m; ++i) {
    ans[c + i] = sub[i];
  }
}
void fill(int c) {
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < cnt[i]; ++j) {
      ans[c] = char('0' + i);
      ++c;
    }
}
int ndig, ldig;
void append() {
  ans[n] = '\0';
  int nd = ndig;
  for (int i = 0; i < ldig; ++i) {
    ans[n - i - 1] = char(nd % 10 + '0');
    nd /= 10;
  }
}
int main() {
  scanf("%s\n%s\n", str, sub);
  n = strlen(str);
  m = strlen(sub);
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; ++i) {
    ++cnt[str[i] - '0'];
  }
  for (int i = 0; i < m; ++i) {
    --cnt[sub[i] - '0'];
  }
  int tot = n - m;
  if (tot < 1) {
    printf("%s\n", sub);
    return 0;
  }
  int l10[] = {7, 6, 5, 4, 3, 2, 1};
  int p10[] = {1000000, 100000, 10000, 1000, 100, 10, 1};
  ndig = 0;
  ldig = 0;
  for (int i = 0; i < 7; ++i) {
    while (n >= max(ldig, l10[i]) + ndig + p10[i]) {
      ldig = max(ldig, l10[i]);
      ndig += p10[i];
    }
  }
  int tmp = ndig;
  for (int i = 0; i < ldig; ++i) {
    --cnt[tmp % 10];
    tmp /= 10;
  }
  for (int i = 0; i < n; ++i) bans[i] = 'Z';
  ans[n] = '\0';
  ins(0);
  fill(m);
  append();
  cpmin();
  if (sub[0] == '0') {
    bans[0] = 'Z';
  }
  if (cnt[0] == tot) {
    printf("%s\n", bans);
    return 0;
  }
  int c = 0;
  for (int i = 1; i < 10; ++i) {
    if (cnt[i] > 0) {
      ans[c] = char('0' + i);
      ++c;
      --cnt[i];
      break;
    }
  }
  if (tot - ldig <= 1) {
    ins(1);
    append();
    if (strstr(ans, sub)) cpmin();
  }
  if (c != 1) {
    bans[n - ldig] = '\0';
    printf("%s\n", bans);
    return 0;
  }
  for (int i = 0; i < 10; ++i) {
    if (cnt[i] < 1) continue;
    ins(c);
    fill(c + m);
    append();
    if (strstr(ans, sub)) cpmin();
    for (int j = 0; j < cnt[i]; ++j) {
      ans[c] = char('0' + i);
      ++c;
    }
    cnt[i] = 0;
    ins(c);
    fill(c + m);
    append();
    if (strstr(ans, sub)) cpmin();
  }
  bans[n - ldig] = '\0';
  printf("%s\n", bans);
  return 0;
}
