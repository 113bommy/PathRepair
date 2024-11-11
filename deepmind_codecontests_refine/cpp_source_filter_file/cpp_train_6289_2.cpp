#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int b[maxn], p[maxn];
int N, M, A;
void read() {
  scanf("%d%d%d", &N, &M, &A);
  for (int i = 1; i <= N; ++i) scanf("%d", &b[i]);
  for (int i = 1; i <= M; ++i) scanf("%d", &p[i]);
}
bool check(int limit) {
  long long need = 0;
  for (int i = 1; i <= limit; ++i) {
    int t = b[N - limit + i] - p[i];
    if (t < 0) need += -t;
  }
  return need <= A;
}
void getans() {
  sort(b + 1, b + 1 + N);
  sort(p + 1, p + 1 + M);
  int l = 1, r = M, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  if (ans == 0)
    cout << 0 << ' ' << 0 << endl;
  else {
    long long sum = 0;
    for (int i = 1; i <= ans; ++i) {
      int t = b[N - ans + i] - p[i];
      sum += p[i];
    }
    cout << ans << ' ' << max(sum - A, 0LL) << endl;
  }
}
int main() {
  read();
  getans();
}
