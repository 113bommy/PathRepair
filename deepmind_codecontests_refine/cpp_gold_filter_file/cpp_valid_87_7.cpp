#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e2 + 5;
int N, M;
int Sight[MAXN * MAXN], Order[MAXN * MAXN], Bac[MAXN * MAXN], Cnt[MAXN * MAXN];
struct seg {
  int T[MAXN * 4];
  void Build(int l, int r, int cur) {
    if (l == r) {
      T[cur] = 0;
      return;
    }
    int m = (l + r) >> 1;
    Build(l, m, cur << 1);
    Build(m + 1, r, cur << 1 | 1);
    T[cur] = T[cur << 1] + T[cur << 1 | 1];
  }
  void Change(int x, int l, int r, int cur) {
    if (l == r) {
      T[cur]++;
      return;
    }
    int m = (l + r) >> 1;
    if (x <= m)
      Change(x, l, m, cur << 1);
    else
      Change(x, m + 1, r, cur << 1 | 1);
    T[cur] = T[cur << 1] + T[cur << 1 | 1];
  }
  int Query(int x, int y, int l, int r, int cur) {
    if (x > y) return 0;
    if (x <= l && r <= y) return T[cur];
    int m = (l + r) >> 1;
    if (x <= m && y > m)
      return Query(x, y, l, m, cur << 1) + Query(x, y, m + 1, r, cur << 1 | 1);
    else if (x <= m)
      return Query(x, y, l, m, cur << 1);
    else
      return Query(x, y, m + 1, r, cur << 1 | 1);
  }
} St[MAXN];
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    cin >> N >> M;
    for (int i = 1; i <= N * M; i++) cin >> Sight[i], Order[i] = Sight[i];
    sort(Order + 1, Order + N * M + 1);
    int num = unique(Order + 1, Order + N * M + 1) - Order - 1;
    for (int i = 1; i <= N; i++) St[i].Build(1, num, 1);
    for (int i = 1; i <= N * M; i++)
      Sight[i] = lower_bound(Order + 1, Order + num + 1, Sight[i]) - Order;
    int Ans = 0;
    for (int i = 1; i <= N * M; i++) {
      Ans += St[1].Query(1, Sight[i] - 1, 1, num, 1);
      St[1].Change(Sight[i], 1, num, 1);
    }
    cout << Ans << endl;
  }
  return 0;
}
