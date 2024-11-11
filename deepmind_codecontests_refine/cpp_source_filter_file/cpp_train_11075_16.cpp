#include <bits/stdc++.h>
using namespace std;
int N, M, X, Y, dx, dy;
map<pair<int, int>, int> F;
void doit() {
  char s[3];
  long long ans = 1;
  scanf("%d%d%d%d", &N, &M, &X, &Y, s), dx = s[0] == 'U' ? -1 : 1,
                                        dy = s[0] == 'L' ? -1 : 1;
  for (int i = 1; i <= (N + M) * 2; i++) {
    F[make_pair(X, Y)] = 1;
    if (F.size() == N + M - 2) {
      cout << ans << endl;
      return;
    }
    int u = dx < 0 ? X - 1 : N - X, v = dy < 0 ? Y - 1 : M - Y, w = min(u, v);
    X += dx * w, Y += dy * w, ans += w;
    if (u == w) dx *= -1;
    if (v == w) dy *= -1;
  }
  puts("-1");
}
int main() {
  doit();
  return 0;
}
