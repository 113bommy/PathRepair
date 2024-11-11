#include <bits/stdc++.h>
using namespace std;
void out(const vector<long long>& v) {
  cerr << endl;
  for (int i = 0; i < v.size(); ++i) cerr << v[i] << " ";
  cerr << endl;
}
vector<long long> f(const vector<long long>& c, int k, int t) {
  int n = c.size();
  vector<long long> queue, res(n);
  int it = 0;
  for (int i = 0; i < min(k, n); ++i) {
    queue.push_back(c[i]);
    res[i] = c[i] + t;
  }
  for (int i = min(k, n); i < n; ++i) {
    long long tin = max(c[i], queue[it] + t);
    queue.push_back(tin);
    ++it;
    res[i] = t + tin;
  }
  return res;
}
int main() {
  long long n;
  vector<long long> k(3), t(3);
  for (int i = 0; i < 3; ++i) cin >> k[i];
  for (int i = 0; i < 3; ++i) cin >> t[i];
  cin >> n;
  vector<long long> c(n);
  for (int i = 0; i < n; ++i) cin >> c[i];
  vector<long long> cur = c;
  for (int i = 0; i < 3; ++i) {
    cur = f(cur, k[i], t[i]);
  }
  long long ma = 0;
  for (int i = 0; i < n; ++i) {
    ma = max(ma, cur[i] - c[i]);
  }
  cout << ma << endl;
  return 0;
}
