#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
void read(int& val) {
  int x = 0;
  int bz = 1;
  char c;
  for (c = getchar(); (c < '0' || c > '9') && c != '-'; c = getchar())
    ;
  if (c == '-') {
    bz = -1;
    c = getchar();
  }
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48;
  val = x * bz;
}
const int mod = 998244353;
const int maxn = 2e5 + 10;
char a[maxn], b[maxn];
int main() {
  int t;
  read(t);
  while (t--) {
    int n;
    read(n);
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    bool ok[40][40];
    memset(ok, 0, sizeof(ok));
    int flag = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] > b[i]) flag = 1;
      if (a[i] == b[i]) continue;
      ok[a[i] - 'a'][b[i] - 'a'] = 1;
    }
    if (flag) {
      puts("-1");
      continue;
    }
    int ans = 0;
    for (int i = 0; i <= 20; i++) {
      int mi = -1;
      for (int j = i + 1; j <= 20; j++) {
        if (ok[i][j]) {
          mi = j;
          break;
        }
      }
      if (mi == -1) continue;
      ans++;
      for (int j = mi + 1; j <= 20; j++) {
        ok[mi][j] |= ok[i][j];
      }
    }
    printf("%d\n", ans);
  }
}
