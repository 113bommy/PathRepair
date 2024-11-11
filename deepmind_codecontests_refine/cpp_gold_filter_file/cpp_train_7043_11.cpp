#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, -1, 0, 1, -1, 0, 1};
int kx8[] = {1, 1, 2, 2, -1, -1, -2, -2};
int ky8[] = {2, -2, 1, -1, 2, -2, 1, -1};
long long bigmod(long long a, long long b, long long c) {
  if (b == 0) return 1 % c;
  long long x = bigmod(a, b / 2, c);
  x = (x * x) % c;
  if (b % 2 == 1) x = (x * a) % c;
  return x;
}
long long mod_inverse(long long a, long long mod) {
  return bigmod(a, mod - 2, mod);
}
const int M = 100005;
long long sum[M], a[M], b[M];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  for (int i = 1; i < n; i++) cin >> a[i];
  long long lw = 0, hi = 1e9, mid, ans = 0;
  while (lw <= hi) {
    mid = (lw + hi) / 2;
    memset((sum), 0, sizeof(sum));
    for (int i = 1; i < n; i++) b[i] = a[i];
    vector<int> pq;
    int ptr = 1;
    sum[0] = mid;
    for (int i = 0; i < n; i++) {
      while ((ptr - i) <= k && ptr < n) {
        pq.push_back(ptr);
        ptr++;
      }
      while (pq.size() && sum[i] > 0) {
        int id = pq.back();
        if (id <= i || b[id] <= 0) {
          pq.pop_back();
          continue;
        }
        if (b[id] >= sum[i]) {
          sum[id] += sum[i];
          b[id] -= sum[i];
          sum[i] = 0;
          break;
        }
        sum[id] += b[id];
        sum[i] -= b[id];
        b[id] = 0;
        pq.pop_back();
      }
    }
    long long tot = 0;
    for (int i = n - 1, j = 1; j <= k; j++, i--) {
      tot += sum[i];
    }
    if (tot == mid) {
      ans = mid;
      lw = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
