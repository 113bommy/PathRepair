#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const long long MOD = 998244353;
const long long maxn = 1e5 + 1;
long long RAND(long long n) { return abs((rand() << 15) + rand()) % n; }
long long num[maxn * 3];
long long pos[maxn * 3];
long long st[maxn * 12];
long long n, N;
long long recur(long long v, long long l, long long r, long long left,
                long long right) {
  if (right <= l || r <= left) return 0;
  if (left <= l && r <= right) return st[v];
  long long mid = (l + r) >> 1;
  long long ans = 0;
  ans += recur(v * 2 + 0, l, mid, left, right);
  ans += recur(v * 2 + 1, mid, r, left, right);
  return ans;
}
void change(long long pos, long long value) {
  pos += N;
  st[pos] = value;
  while (1 < pos) {
    pos /= 2;
    st[pos] = st[pos * 2 + 0] + st[pos * 2 + 1];
  }
}
void solveTask() {
  cin >> n;
  for (N = 1; N <= n; N *= 2)
    ;
  for (int i = 1; i <= n; ++i) {
    cin >> num[i];
    pos[num[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    if (pos[i] < pos[i + 1])
      change(i, 0);
    else
      change(i, 1);
  }
  long long q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    long long type, x, y;
    cin >> type >> x >> y;
    if (type == 1) {
      cout << 1 + recur(1, 0, N, x, y) << '\n';
    } else {
      long long nx = num[x];
      long long ny = num[y];
      swap(num[x], num[y]);
      swap(pos[nx], pos[ny]);
      for (int i = 0; i < 2; ++i) {
        long long t = i == 0 ? nx : ny;
        if (t != 1) change(t - 1, pos[t - 1] < pos[t] ? 0 : 1);
        if (t != n) change(t, pos[t] < pos[t + 1] ? 0 : 1);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  srand(time(0));
  solveTask();
  return 0;
}
