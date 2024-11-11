#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> Pos[120005];
long long d[120005], h[120005];
const pair<long long, long long> inf = make_pair(-(1LL << 60), -(1LL << 60));
struct rec {
  pair<long long, long long> Min, Max;
  void Init() {
    Min = inf;
    Max = inf;
  }
} Ret, RetL, RetR;
int ll, rr;
struct seg {
  rec Data[4 * 120005];
  void Merge(rec &A, rec B) {
    if (B.Max > A.Max) swap(A, B);
    if (B.Max > A.Min) A.Min = B.Max;
  }
  void Built(int t, int l, int r) {
    if (l == r) {
      Data[t].Min = inf;
      Data[t].Max = Pos[l];
      return;
    }
    int mid = (l + r) >> 1;
    Built(t * 2, l, mid);
    Built(t * 2 + 1, mid + 1, r);
    Data[t].Init();
    Merge(Data[t], Data[t * 2]);
    Merge(Data[t], Data[t * 2 + 1]);
  }
  void Query(int t, int l, int r) {
    if (ll <= l && r <= rr) {
      Merge(Ret, Data[t]);
      return;
    }
    int mid = (l + r) >> 1;
    if (ll <= mid) Query(t * 2, l, mid);
    if (rr > mid) Query(t * 2 + 1, mid + 1, r);
  }
} Seg[2];
int main() {
  int n, Q_Q;
  scanf("%d%d", &n, &Q_Q);
  for (int i = 1; i <= n; i++) scanf("%I64d", &d[i]);
  for (int i = 1; i <= n; i++) scanf("%I64d", &h[i]), h[i] *= 2;
  long long sum = 0;
  for (int i = 1; i <= n; i++) Pos[i] = make_pair(h[i] - sum, i), sum += d[i];
  sum = 0;
  Seg[0].Built(1, 1, n);
  for (int i = 1; i <= n; i++) Pos[i] = make_pair(h[i] + sum, i), sum += d[i];
  sum = 0;
  Seg[1].Built(1, 1, n);
  for (int i = 1; i <= n; i++) sum += d[i];
  while (Q_Q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    long long Ans = 0;
    if (x <= y) {
      ll = y + 1;
      rr = n;
      if (ll <= rr) {
        Ret.Init();
        Seg[0].Query(1, 1, n);
        RetL = Ret;
        Ret.Init();
        Seg[1].Query(1, 1, n);
        RetR = Ret;
        if (RetL.Max.second != RetR.Max.second) {
          Ans = max(Ans, RetL.Max.first + RetR.Max.first);
        } else {
          Ans = max(Ans, RetL.Max.first + RetR.Min.first);
          Ans = max(Ans, RetL.Min.first + RetR.Max.first);
        }
      }
      ll = 1;
      rr = x - 1;
      if (ll <= rr) {
        Ret.Init();
        Seg[0].Query(1, 1, n);
        RetL = Ret;
        Ret.Init();
        Seg[1].Query(1, 1, n);
        RetR = Ret;
        if (RetL.Max.second != RetR.Max.second) {
          Ans = max(Ans, RetL.Max.first + RetR.Max.first);
        } else {
          Ans = max(Ans, RetL.Max.first + RetR.Min.first);
          Ans = max(Ans, RetL.Min.first + RetR.Max.first);
        }
      }
      if (y + 1 <= n && 1 <= x - 1) {
        ll = y + 1;
        rr = n;
        Ret.Init();
        Seg[0].Query(1, 1, n);
        RetL = Ret;
        ll = 1;
        rr = x - 1;
        Ret.Init();
        Seg[1].Query(1, 1, n);
        RetR = Ret;
        Ans = max(Ans, RetL.Max.first + RetR.Max.first + sum);
      }
    } else {
      ll = y + 1;
      rr = x - 1;
      Ret.Init();
      Seg[0].Query(1, 1, n);
      RetL = Ret;
      Ret.Init();
      Seg[1].Query(1, 1, n);
      RetR = Ret;
      if (RetL.Max.second != RetR.Max.second) {
        Ans = max(Ans, RetL.Max.first + RetR.Max.first);
      } else {
        Ans = max(Ans, RetL.Max.first + RetR.Min.first);
        Ans = max(Ans, RetL.Min.first + RetR.Max.first);
      }
    }
    printf("%I64d\n", Ans);
  }
}
