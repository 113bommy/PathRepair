#include <bits/stdc++.h>
using namespace std;
int f[101000][2];
int n;
struct node {
  int a;
  int b;
  int c;
} s[101000];
int main() {
  cin >> n;
  for (register int i = 1; i <= n; ++i) {
    cin >> s[i].a;
  }
  for (register int i = 1; i <= n; ++i) {
    cin >> s[i].b;
  }
  for (register int i = 1; i <= n; ++i) {
    cin >> s[i].c;
  }
  memset(f, 0xcf, sizeof(f));
  f[1][0] = 0;
  for (register int i = 2; i <= n + 1; ++i) {
    f[i][0] = max(f[i - 1][1] + s[i - 1].c, f[i - 1][0] + s[i - 1].b);
    f[i][1] = max(f[i - 1][0] + s[i - 1].a, f[i - 1][1] + s[i - 1].b);
  }
  cout << f[n + 1][1];
  return 0;
}
