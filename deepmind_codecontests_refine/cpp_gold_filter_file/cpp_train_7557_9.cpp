#include <bits/stdc++.h>
using namespace std;
char good[30];
bool isGood[30];
int n, m, q;
char str[120000], word[120000];
void input() {}
bool wf() {
  m = strlen(word);
  int i, j, k = n;
  for (i = 0; i < n; i++) {
    if (str[i] == word[i]) {
      continue;
    }
    if (str[i] == '?') {
      if (!isGood[word[i] - 'a']) return false;
    }
    if (str[i] == '*') {
      k = i;
      break;
    }
    if (str[i] != '?' && str[i] != word[i]) {
      return false;
    }
  }
  if (k == n) {
    return n == m;
  }
  i = n - 1;
  j = m - 1;
  while (i >= 0 && j >= k) {
    if (str[i] == word[j]) {
      i--;
      j--;
      continue;
    }
    if (str[i] == '?' && !isGood[word[j] - 'a']) {
      return false;
    }
    if (str[i] == '*') break;
    if (str[i] != '?' && str[i] != word[j]) {
      return false;
    }
    i--;
    j--;
  }
  if (j < k && i >= 0 && str[i] != '*') {
    return false;
  }
  if (i >= 0 && str[i] == '*') {
    for (i = k; i <= j; i++) {
      if (isGood[word[i] - 'a']) {
        return false;
      }
    }
  }
  return true;
}
void solve() {
  int i, j, k;
  for (i = 0; i < 26; i++) {
    isGood[i] = false;
  }
  for (i = 0; good[i]; i++) {
    isGood[good[i] - 'a'] = 1;
  }
  n = strlen(str);
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%s", &word);
    if (wf()) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}
int main() {
  while (scanf("%s %s", &good, &str) != EOF) {
    solve();
  }
  return 0;
}
