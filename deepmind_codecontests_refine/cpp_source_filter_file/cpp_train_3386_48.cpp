#include <bits/stdc++.h>
using namespace std;
class CHT {
 public:
  deque<pair<long long, long long> > Hull;
  long long type = 1;
  long long getVal(pair<long long, long long> a, long long x) {
    return a.first * x + a.second;
  }
  long long cmp(pair<long long, long long> a, pair<long long, long long> b,
                pair<long long, long long> c) {
    return (type ^ ((b.second - c.second) * (b.first - a.first) <=
                    (a.second - b.second) * (c.first - b.first)));
  }
  void insert(long long inc, long long y) {
    Hull.push_back({inc, y});
    int v;
    while ((v = Hull.size()) >= 3 && cmp(Hull[v - 3], Hull[v - 2], Hull[v - 1]))
      Hull[v - 2] = Hull[v - 1], Hull.pop_back();
  }
  long long query(long long x) {
    long long L = -1, R = Hull.size() - 1;
    while (R - L > 1) {
      long long M = (L + R) / 2;
      ((((getVal(Hull[M], x) <= getVal(Hull[M + 1], x)))) ? L : R) = M;
    }
    return getVal(Hull[R], x);
  }
  void print() {
    for (auto x : Hull) {
      cout << x.first << " " << x.second << endl;
    }
  }
};
long long n;
long long a[200010], second[200010];
long long ans = 0, t;
CHT c1, c2;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    t += i * a[i];
    second[i] = second[i - 1] + a[i];
  }
  c1.type = 0;
  c1.insert((long long)1, -second[0]);
  for (long long i = 2; i <= n; i++) {
    ans = max(ans, c1.query(a[i]) - i * a[i] + second[i - 1]);
    c1.insert(i, -second[i - 1]);
  }
  c2.type = 1;
  c2.insert(-n, -second[n]);
  for (long long i = n - 1; i >= 1; i--) {
    ans = max(ans, c2.query(-a[i]) - i * a[i] + second[i]);
    c2.insert(-i, -second[i]);
  }
  cout << ans + t << endl;
}
