#include <bits/stdc++.h>
using namespace std;
const int SIZEN = 100010;
const int MOD = 1000000007;
int pow2(int n) {
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = (ans << 1) % MOD;
  }
  return ans;
}
class EQ2 {
 public:
  int ufs[SIZEN * 2];
  void clear(void) { memset(ufs, -1, sizeof(ufs)); }
  EQ2() { clear(); }
  int grand(int x) { return ufs[x] == -1 ? x : ufs[x] = grand(ufs[x]); }
  bool merge(int a, int b) {
    int ga = grand(a), gb = grand(b);
    if (grand(a ^ 1) == gb) return false;
    if (grand(b ^ 1) == ga) return false;
    if (ga != gb) ufs[ga] = gb;
    return true;
  }
  bool test(int a, int b, int t) {
    if (t == 0) {
      return merge(2 * a, 2 * b) && merge(2 * a + 1, 2 * b + 1);
    } else if (t == 1) {
      return merge(2 * a, 2 * b + 1) && merge(2 * a + 1, 2 * b);
    }
  }
  int count(int N) {
    N = 2 * N + 1;
    int ans = 0;
    for (int i = 0; i <= N; i++) {
      if (grand(i) == i) ans++;
    }
    return ans;
  }
} S;
void work(void) {
  int N, K, a, b, p;
  char ch[10];
  scanf("%d%d", &N, &K);
  for (int i = 1; i <= K; i++) {
    scanf("%d%d", &a, &b);
    a--, b--;
    scanf("%s", ch);
    p = (ch[0] == 'x' ? 0 : 1);
    int l = abs(a - b);
    int r = min(a + b, 2 * (N - 1) - (a + b));
    if (!S.test(l, r + 2, p)) {
      printf("0\n");
      return;
    }
  }
  int cnt = S.count(N + 1);
  printf("%d\n", pow2((cnt - 4) / 2));
}
int main() {
  work();
  return 0;
}
