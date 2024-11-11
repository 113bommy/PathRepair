#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct custom_hash {
  static unsigned long long splitmix64(unsigned long long x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(unsigned long long x) const {
    static const unsigned long long FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
mt19937 random_generator(
    chrono::steady_clock::now().time_since_epoch().count());
const int maxn = 1e5 + 3;
int n;
long long k;
int a[maxn];
void read() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
}
int val[maxn];
bool can(long long x) {
  long long cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] - 1 < x) {
      val[i] = -1;
      continue;
    }
    int low = 0, high = a[i] - 1;
    while (low < high) {
      int mid = (low + high + 1) / 2;
      long long val = a[i] - 3ll * mid * mid - 3ll * mid - 1ll;
      if (val >= x)
        low = mid;
      else
        high = mid - 1;
    }
    val[i] = low;
    cnt += low + 1;
  }
  return cnt >= k;
}
void solve() {
  long long low = -4e18, high = 4e18;
  while (low < high) {
    long long mid = (low + high + 1) / 2;
    if (can(mid))
      low = mid;
    else
      high = mid - 1;
  }
  can(low);
  priority_queue<pair<long long, int> > q;
  for (int i = 1; i <= n; i++)
    q.push({-(a[i] - 3ll * val[i] * val[i] - 3ll * val[i] - 1), i});
  int cnt = 0;
  for (int i = 1; i <= n; i++) cnt += val[i] + 1;
  while (cnt > k) {
    auto curr = q.top();
    q.pop();
    val[curr.second]--;
    cnt--;
    if (val[curr.second] != -1)
      q.push({-(a[curr.second] - 3ll * val[curr.second] * val[curr.second] -
                3ll * val[curr.second] - 1),
              curr.second});
  }
  for (int i = 1; i <= n; i++) cout << val[i] + 1 << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  read();
  solve();
}
