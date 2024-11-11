#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e14;
const long double eps = 1e-6;
long long q1(long long a, long long b, long long c) {
  cout << 1 << " " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
  long long s;
  cin >> s;
  return s;
}
long long q2(long long a, long long b, long long c) {
  cout << 2 << " " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
  long long s;
  cin >> s;
  return s;
}
vector<long long> h;
bool cmp(long long a, long long b) { return h[a] < h[b]; }
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  long long v = 0, u = rand() % (n - 1) + 1;
  vector<long long> used(n, 0);
  used[v] = 1, used[u] = 1;
  for (long long i = 0; i < n - 2; ++i) {
    long long k;
    for (long long j = 0; j < n; ++j) {
      if (!used[j]) {
        k = j;
        break;
      }
    }
    used[k] = 1;
    long long s = q1(v, u, k);
    if (s == 1) u = k;
  }
  vector<long long> p;
  for (long long i = 0; i < n; ++i)
    if (i != u && i != v) p.push_back(i);
  h.resize(n);
  for (long long i = 0; i < n; ++i) {
    if (i != u && i != v) h[i] = q2(v, u, i);
  }
  sort(p.begin(), p.end(), cmp);
  deque<long long> d;
  d.push_back(v), d.push_front(u);
  used.assign(n, 0);
  used[v] = 1, used[u] = 1;
  for (long long i = 0; i < n - 2; ++i) {
    long long k = p[i];
    for (long long j = 0; j < n; ++j) {
      if (!used[j] && k != j) {
        used[k] = 1;
        if (q1(u, k, j) == 1) {
          d.push_back(k);
          v = k;
        } else {
          d.push_front(k);
          u = k;
        }
        break;
      }
    }
  }
  for (long long i = 0; i < n; ++i)
    if (!used[i]) d.push_back(i);
  vector<long long> ans;
  while (d.front() != 0) {
    ans.push_back(d.front());
    d.pop_front();
  }
  reverse(ans.begin(), ans.end());
  while ((long long)d.size()) {
    ans.push_back(d.back());
    d.pop_back();
  }
  reverse(ans.begin(), ans.end());
  cout << "0 ";
  for (long long x : ans) cout << x + 1 << " ";
  cout << endl;
  return 0;
}
