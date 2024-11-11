#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxn = 2e5 + 10;
int a[maxn];
char s[maxn];
const char *t = "LR";
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  scanf("%s", s);
  bool rev = s[0] == 'R';
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    cnt += s[i] == s[i - 1];
  }
  printf("%d %c\n", a[cnt], t[rev]);
  int l = cnt, r = cnt;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1])
      l--, printf("%d %c\n", a[l], t[((cnt - l) & 1) ^ rev]);
    else
      r++, printf("%d %c\n", a[r], t[((r - cnt) & 1) ^ rev]);
  }
}
