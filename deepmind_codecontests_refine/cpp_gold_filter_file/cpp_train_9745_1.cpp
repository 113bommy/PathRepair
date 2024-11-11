#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 10;
string str;
int len, ans[maxn];
int a[maxn][maxn];
int b[maxn][maxn];
void init() {
  cin >> str;
  memset(b, -1, sizeof(b));
  len = str.size();
}
void solve() {
  for (int i = 0; i < len; i++) {
    for (int j = i, k = i; j >= 0 && k < len; j--, k++) {
      a[j][k] = (str[j] == str[k]);
      if (str[j] != str[k]) break;
    }
    if (i < len - 1) {
      for (int j = i, k = i + 1; j >= 0 && k < len; j--, k++) {
        a[j][k] = (str[j] == str[k]);
        if (str[j] != str[k]) break;
      }
    }
  }
}
int Search(int l, int r) {
  if (a[l][r] == 0) return 0;
  if (b[l][r] == -1) {
    int len = (r - l + 1) / 2;
    b[l][r] = min(Search(l, l + len - 1), Search(r - len + 1, r)) + 1;
  }
  return b[l][r];
}
void answer() {
  for (int i = 0; i < len; i++) {
    for (int j = i; j < len; j++) {
      ans[Search(i, j)]++;
    }
  }
  for (int i = len - 1; i >= 1; i--) {
    ans[i] += ans[i + 1];
  }
  for (int i = 1; i <= len; i++) {
    printf("%d%c", ans[i], i == len ? '\n' : ' ');
  }
}
int main() {
  init();
  solve();
  answer();
  return 0;
}
