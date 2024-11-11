#include <bits/stdc++.h>
using namespace std;
long long R = pow(10, 9) + 7;
template <typename T>
T last(vector<T>& v) {
  return v[v.size() - 1];
}
template <typename T>
void prll(vector<T>& v) {
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  cout << endl;
}
template <typename T1, typename T2>
void prll(vector<pair<T1, T2>>& v) {
  cout << "[";
  for (long long i = 0; i < v.size(); i++) {
    cout << '(' << v[i].first << ',' << v[i].second << "),";
  }
  cout << "]" << endl;
}
template <typename T>
void prll(vector<vector<T>>& v) {
  cout << "[";
  for (long long i = 0; i < v.size(); i++) {
    prll(v[i]);
  }
  cout << "]" << endl;
}
template <typename T>
void prll(set<T>& v) {
  cout << "{";
  for (auto i : v) {
    cout << i << ' ';
  }
  cout << "}" << endl;
}
template <typename T1, typename T2>
void prll(map<T1, T2>& v) {
  cout << "{";
  for (auto i : v) {
    cout << i.first << ':' << i.second << ',';
  }
  cout << "}" << endl;
}
template <typename T>
bool in(set<T>& indices, T x) {
  return indices.find(x) != indices.end();
}
template <typename T, typename T_>
bool in(map<T, T_>& indices, T x) {
  return indices.find(x) != indices.end();
}
long long power(long long x, long long y) {
  long long res = 1;
  x = x % R;
  if (x == 0) return 0;
  while (y > 0) {
    if (y % 2 == 1) res = (res * x) % R;
    y /= 2;
    x = (x * x) % R;
  }
  return res;
}
bool compare(long long a, long long b) { return (a < b); }
bool impossible = false;
long long ans = 0;
vector<long long> a;
long long x, y, k;
long long solve(long long l, long long r) {
  long long len = r - l - 1;
  if (len == 0) return 0;
  long long ma = a[l + 1];
  for (long long i = l + 1; i < r; i++) {
    ma = max(ma, a[i]);
  }
  if (ma < a[l] || ma < a[r]) {
    if (k * y >= x) {
      return (len / k) * x + (len % k) * y;
    } else {
      return len * y;
    }
  } else if (len < k) {
    impossible = true;
    return 0;
  } else {
    if (k * y >= x) {
      return (len / k) * x + (len % k) * y;
    } else {
      return x + (len - x) * y;
    }
  }
}
void TestCase() {
  long long n, m;
  cin >> n >> m;
  cin >> x >> k >> y;
  a.resize(n + 2, 0);
  for (long long i = 1; i <= n; i++) cin >> a[i];
  vector<long long> b(m);
  for (long long i = 0; i < m; i++) cin >> b[i];
  n += 2;
  long long index = 0;
  long long j = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] == b[j]) {
      ans += solve(index, i);
      j++;
      index = i;
    }
    if (j == m) break;
  }
  ans += solve(index, n - 1);
  if (j != m || impossible) {
    cout << -1 << '\n';
    return;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T;
  T = 1;
  for (long long tt = 1; tt <= T; tt++) {
    TestCase();
  }
}
