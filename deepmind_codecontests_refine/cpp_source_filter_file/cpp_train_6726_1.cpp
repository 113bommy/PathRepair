#include <bits/stdc++.h>
using namespace std;
void cmax(int &x, const int &y) { x = x > y ? x : y; }
void cmin(int &x, const int &y) { x = x < y ? x : y; }
int n, len;
const int N = 2e5 + 5;
char s[N][21];
int mn[1 << 21];
void reverse(char *s, int length) {
  int i = 1, j = length;
  while (i < j) swap(s[i], s[j]), ++i, --j;
}
int getmin(char *s, int length) {
  int p = 0;
  for (int i = 1; i <= length; i++) p = p << 1 | (s[i] ^ '0');
  return mn[p];
}
int query(char *s) {
  int result = 0x3f3f3f3f;
  for (int i = 0; i <= len; i++) {
    reverse(s, i);
    cmin(result, getmin(s, i) + len - i);
    reverse(s, i);
  }
  return result;
}
int solve(char *s, char *t) {
  int result = 0;
  for (int i = len; i; --i) {
    int flag = 1;
    for (int j = len; flag && len - j < i; --j)
      if (s[j] != t[i - (len - j)]) flag = 0;
    if (flag) {
      result = i;
      break;
    }
  }
  return len - result;
}
void insert(char *s, int v) {
  int p = 0;
  for (int i = 1; i <= len; i++) {
    cmin(mn[p], v);
    p = p << 1 | (s[i] ^ '0');
  }
  cmin(mn[p], v);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i] + 1;
  len = strlen(s[1] + 1);
  int tag = len;
  memset(mn, 0x3f, sizeof(mn));
  mn[0] = 0;
  for (int i = 2; i <= n; i++) {
    int result = query(s[i]);
    result += tag;
    tag += solve(s[i - 1], s[i]);
    reverse(s[i - 1], len);
    insert(s[i - 1], result - tag);
  }
  int ans = mn[0] + tag;
  cout << ans << '\n';
  return 0;
}
