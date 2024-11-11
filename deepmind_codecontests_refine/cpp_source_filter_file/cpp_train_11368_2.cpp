#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char s[N];
int len;
int f[N];
int c[N];
int cnt[26];
int mx;
int pos;
unordered_map<int, int> mp;
int find(int x) { return (x == f[x]) ? x : (f[x] = find(f[x])); }
void mrg(int a, int b) {
  int x = find(a);
  int y = find(b);
  if (x == y) return;
  f[y] = x;
  c[x] += c[y];
  if (mx < c[x]) {
    pos = x;
    mx = c[x];
  }
}
int main() {
  scanf("%s", s);
  len = strlen(s);
  for (int i = 0; i < len; ++i) {
    cnt[s[i] - 'a']++;
  }
  memset(s, 0, sizeof(s));
  for (int i = 1; i <= len; ++i) {
    f[i] = i;
    c[i] = 1;
  }
  for (int i = 2; i <= len; ++i) {
    if (i == f[i]) {
      for (int j = 2 * i; j <= len; j += i) {
        mrg(i, j);
      }
    }
  }
  int tmx = 0;
  int tpos = 0;
  for (int i = 0; i < 26; ++i) {
    if (tmx < cnt[i]) {
      tmx = cnt[i];
      tpos = i;
    }
  }
  if (mx < tmx) {
    printf("YES\n");
    for (int i = 1; i <= len; ++i) {
      if (find(i) == pos) {
        s[i] = tpos + 'a';
      }
    }
    cnt[tpos] -= mx;
    int p = 0;
    for (int i = 1; i <= len; ++i) {
      if (find(i) != pos) {
        while (cnt[p] <= 0) p++;
        s[i] = p + 'a';
        cnt[p]--;
      }
    }
    s[len + 1] = 0;
    printf("%s\n", s + 1);
  } else {
    printf("NO\n");
  }
  return 0;
}
