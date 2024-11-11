#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const int MAXN = 100005;
int a[MAXN], b[MAXN], ans1[MAXN], ans2[MAXN], mark[MAXN];
int i, j, k, N, L, S, id, cnt, cc;
long long sum1, sum2;
pair<int, int> Left[MAXN];
void init() {
  scanf("%d%d%d", &N, &L, &S);
  for (i = 1; i <= N; i++) scanf("%d", &a[i]);
}
inline long long Solve(int x[], int S, int L, int ans[]) {
  if (S >= N) return INF;
  if (S > L) {
    for (mark[S] = ++id, i = 1; i < L; i++) ans[i] = S - i, mark[S - i] = id;
    ans[L] = 1, mark[1] = id;
    for (i = 2, k = L; i <= N; i++)
      if (mark[i] < id) mark[i] = id, ans[++L] = i;
    return x[N] + x[S];
  }
  for (i = 1, mark[S] = ++id; i < S; i++) ans[i] = S - i, mark[S - i] = id;
  int mip = S + 1;
  long long best = 2 * x[N] - x[S] - x[S + 1], cur, triple = 0;
  L -= (S - 1);
  priority_queue<int> h;
  if (S + L + 1 < N)
    for (i = S + 2; i <= N; i++) {
      if (N - i >= L) {
        if ((cur = 2 * x[N] - x[S] - x[i]) < best) best = cur, mip = i;
      } else {
        triple -= h.top(), h.pop();
        cur = triple * 3 + 2 * x[N] - x[S] - x[i];
        if (cur < best) best = cur, mip = i;
      }
      h.push(x[i - 1] - x[i]);
    }
  for (i = S + 2, cnt = S - 1, cc = 0; i < mip; i++)
    Left[++cc] = make_pair(x[i] - x[i - 1], i - 1);
  sort(Left + 1, Left + cc + 1);
  for (i = 1, ++id; i <= L - N + mip; i++) mark[Left[i].second] = id;
  if (L - N + mip > 0) {
    for (i = S + 1; i < mip; i = j + 1) {
      for (j = i; mark[j] >= id; j++)
        ;
      for (k = j; k >= i; ans[++cnt] = k--)
        ;
    }
    for (i = N - 1, ans[++cnt] = N; i >= mip; i--) ans[++cnt] = i;
  } else {
    for (i = S + 1; i < mip; i++) ans[++cnt] = i;
    int ll = N - mip - L;
    for (i = 1, ++id; i <= ll; i++) ans[++cnt] = i, mark[i] = id;
    for (i = N; i >= mip; i--)
      if (mark[i] < id) ans[++cnt] = i;
  }
  return best + 2 * x[S];
}
bool NoSol(int N, int S, int L) {
  if (!L && S > 1) return 1;
  if (L + 1 >= N && S < N) return 1;
  return 0;
}
void work() {
  if (NoSol(N, S, L)) {
    puts("-1");
    return;
  }
  sum1 = Solve(a, S, L, ans1);
  for (i = 1; i <= N; i++) b[i] = a[N] - a[N - i + 1];
  sum2 = Solve(b, N - S + 1, N - L - 1, ans2);
  if (sum1 < sum2) {
    printf("%I64d\n", sum1);
    for (i = 1; i < N; i++) printf("%d%c", ans1[i], (i + 1 < N ? ' ' : '\n'));
  } else {
    printf("%I64d\n", sum2);
    for (i = 1; i < N; i++)
      printf("%d%c", N - ans2[i] + 1, (i + 1 < N ? ' ' : '\n'));
  }
}
int main() {
  init();
  work();
  return 0;
}
