#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 1;
const long long MD = 1e9 + 7;
const long long MAXN = 1e4 + 5;
const long long base = 1000 * 1000 * 1000;
const long long cnst = 5e5;
const long long K = 167;
struct query {
  long long num, l, r;
  const bool operator<(const query &cur) const {
    if (l / K == cur.l / K) return r < cur.r;
    return l / K < cur.l / K;
  }
};
struct read {
  long long l1, r1, l2, r2;
};
long long n, m, q;
pair<long long, long long> ans[1000006];
signed main() {
  cin >> n >> q;
  deque<long long> dq;
  for (long long i = 1; i <= n; i++) {
    long long val;
    cin >> val;
    dq.push_back(val);
  }
  for (long long i = 1; i <= n; i++) {
    long long a = dq.front();
    dq.pop_front();
    long long b = dq.front();
    dq.pop_front();
    ans[i] = {a, b};
    if (a > b) {
      dq.push_front(a);
      dq.push_back(b);
    } else {
      dq.push_front(b);
      dq.push_back(a);
    }
  }
  vector<long long> v;
  for (long long i = 1; i <= n; i++) {
    long long a = dq.front();
    dq.pop_front();
    v.push_back(a);
  }
  while (q--) {
    long long num = 0;
    cin >> num;
    if (num <= n) {
      cout << ans[num].first << " " << ans[num].second << "\n";
    } else {
      if (n != 2) {
        long long a = (num - n) % (n - 1);
        if (a == 0) {
          a = n;
        }
        cout << v[0] << " " << v[a] << "\n";
      } else {
        cout << v[0] << " " << v[1] << "\n";
      }
    }
  }
}
