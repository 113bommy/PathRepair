#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  return b ? power(a * a % 1000000007ll, b / 2) * (b % 2 ? a : 1) % 1000000007ll
           : 1;
}
long long gcd(long long a, long long b) {
  if (a == 0 || b == 0) return max(a, b);
  if (a == 1 || b == 1) return 1;
  return gcd(max(a, b) % min(a, b), min(a, b));
}
int n;
vector<long long> task;
vector<long long> a1;
vector<long long> b1;
vector<long long> t1;
vector<long long> t2;
long long sum1(int k) {
  long long ans = 0;
  while (k >= 1) {
    ans += t1[k];
    k -= k & (-1 * k);
  }
  return ans;
}
long long sum2(int k) {
  long long ans = 0;
  while (k >= 1) {
    ans += t2[k];
    k -= k & (-1 * k);
  }
  return ans;
}
void update1(int k, int diff) {
  while (k <= n) {
    t1[k] += diff;
    k += k & (-1 * k);
  }
}
void update2(int k, int diff) {
  while (k <= n) {
    t2[k] += diff;
    k += k & (-1 * k);
  }
}
void solve() {
  int k, a, b, q;
  cin >> n >> k >> a >> b >> q;
  a1.assign(n + 1, 0);
  b1.assign(n + 1, 0);
  t1.assign(n + 1, 0);
  t2.assign(n + 1, 0);
  task.assign(n + 1, 0);
  while (q--) {
    int x;
    cin >> x;
    if (x == 2) {
      int y;
      cin >> y;
      cout << sum1(y - 1) + sum2(n) - sum2(min(n, y + k - 1)) << endl;
    } else {
      int y, z;
      cin >> y >> z;
      task[y] += z;
      if (min(b * 1ll, task[y]) > a1[y]) {
        update1(y, min(b * 1ll, task[y]) - a1[y]);
        a1[y] = min(b * 1ll, task[y]);
      }
      if (min(a * 1ll, task[y]) > b1[y]) {
        update2(y, min(a * 1ll, task[y]) - b1[y]);
        b1[y] = min(a * 1ll, task[y]);
      }
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int te = 1;
  while (te--) solve();
  return 0;
}
