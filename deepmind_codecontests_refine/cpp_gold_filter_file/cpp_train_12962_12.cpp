#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 23;
int n, cur, fail[maxn], a[maxn], b[maxn];
char s[maxn];
void get_fail() {
  cur = 0, fail[1] = 0;
  for (int i = 1; i <= n; i++) {
    while ((cur > 0) && (b[i + 1] != b[cur + 1])) cur = fail[cur];
    if (b[i + 1] == b[cur + 1]) cur++;
    fail[i + 1] = cur;
  }
}
int KMP() {
  cur = 0;
  for (int i = 1; i <= n; i++) {
    while ((cur) && (a[i] != b[cur + 1])) cur = fail[cur];
    if (a[i] == b[cur + 1]) cur++;
  }
  return cur;
}
int matc(char c) {
  if (c == 'N') return 0;
  if (c == 'E') return 1;
  if (c == 'S') return 2;
  if (c == 'W') return 3;
}
int main() {
  scanf("%d", &n);
  n--;
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) a[i] = matc(s[i]);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) b[i] = matc(s[n - i + 1]) ^ 2;
  get_fail();
  if (KMP())
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}
