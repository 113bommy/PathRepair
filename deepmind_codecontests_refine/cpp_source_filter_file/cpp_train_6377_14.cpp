#include <bits/stdc++.h>
using namespace std;
char str[300000 + 5];
int vow[300000 + 5], con[300000 + 5];
pair<int, int> diff[300000 + 5];
const char *vowchar = "AEIOUaeiou";
int main() {
  gets(str);
  int n = strlen(str);
  int maxlen = 0, maxcnt = 0;
  for (int i = 0; i < n; ++i) {
    if (i) {
      vow[i] = vow[i - 1];
      con[i] = con[i - 1];
    }
    if (strchr(vowchar, str[i])) {
      str[i] = '0';
      vow[i]++;
    } else {
      str[i] = '1';
      con[i]++;
    }
    diff[i].first = vow[i] - 2 * con[i];
    diff[i].second = i;
  }
  sort(diff, diff + n);
  for (int i = 0, j = 1; i < n; i = j) {
    for (j = i + 1; j < n && diff[j].first == diff[i].first; ++j)
      ;
    int currlen = diff[j - 1].second - diff[i].second;
    maxlen = max(maxlen, currlen);
  }
  int nvow = 0, ncon = 0;
  for (int pos = 0; pos < n; ++pos) {
    if (str[pos] == '0')
      nvow++;
    else
      ncon++;
    if (nvow <= 2 * ncon) {
      maxlen = max(maxlen, pos);
    }
  }
  nvow = ncon = 0;
  for (int pos = n - 1; pos >= 0; --pos) {
    if (str[pos] == '0')
      nvow++;
    else
      ncon++;
    if (nvow <= 2 * ncon) {
      maxlen = max(maxlen, n - pos);
    }
  }
  if (maxlen) {
    int nvow = 0, ncon = 0;
    for (int i = 0; i < maxlen; ++i) {
      if (str[i] == '0')
        nvow++;
      else
        ncon++;
    }
    if (nvow <= 2 * ncon) maxcnt++;
    for (int i = 0, j = maxlen; i < n && j < n; ++i, ++j) {
      if (str[i] == '0')
        nvow--;
      else
        ncon--;
      if (str[j] == '0')
        nvow++;
      else
        ncon++;
      if (nvow <= 2 * ncon) maxcnt++;
    }
    printf("%d %d\n", maxlen, maxcnt);
  } else
    puts("No solution");
}
