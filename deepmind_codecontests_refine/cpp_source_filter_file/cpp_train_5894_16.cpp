#include <bits/stdc++.h>
using namespace std;
namespace FGF {
int n, m;
int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') w = -w;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * w;
}
const int N = 3e5 + 5;
int num, cnt, nxt[N << 1][2], siz[N << 1][2];
bool vis[N];
void inser(int x) {
  int now = 0;
  for (int i = 1 << 20; i; i >>= 1) {
    bool c = x & i;
    if (!nxt[now][c]) nxt[now][c] = ++cnt;
    siz[now][c]++;
    now = nxt[now][c];
  }
}
int query(int x) {
  int now = 0, ans = 0;
  for (int i = 1 << 20; i; i >>= 1) {
    bool c = x & i;
    if (siz[now][c] < i) {
      now = nxt[now][c];
      if (!now) return ans;
    } else {
      now = nxt[now][c ^ 1];
      ans |= i;
      if (!now) return ans;
    }
  }
  return ans;
}
void work() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    int x = read();
    if (!vis[x]) inser(x);
    vis[x] = 1;
  }
  while (m--) {
    int x = read();
    num ^= x;
    printf("%d\n", query(num));
  }
}
}  // namespace FGF
int main() {
  FGF::work();
  return 0;
}
