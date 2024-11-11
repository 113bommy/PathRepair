#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
char s[100011];
int flag[26];
int vst[26];
int main() {
  int n;
  cin >> n;
  char c;
  int ans = 0, m, f = 0, cnt = 26;
  for (int i = 0; i < n - 1; i++) {
    scanf(" %c %s ", &c, s);
    if (c == '!') {
      if (f) {
        ans++;
        continue;
      }
      m = strlen(s);
      for (int j = 0; j < m; j++) {
        vst[s[j] - 'a'] = 1;
      }
      for (int j = 0; j < 26; j++)
        if (!vst[j] and flag[j] == 0) flag[j] = 1, cnt--;
      for (int j = 0; j < 26; j++) vst[j] = 0;
    }
    if (c == '.' and f == 0) {
      m = strlen(s);
      for (int j = 0; j < m; j++) {
        if (flag[s[j] - 'a'] == 0) cnt--, flag[s[j] - 'a'] = 1;
      }
    }
    if (c == '?') {
      if (flag[s[0] - 'a'] == 0) flag[s[0] - 'a'] = 1, cnt--;
      if (f) ans++;
    }
    if (cnt == 1) f = 1;
  }
  cout << ans << endl;
  return 0;
}
