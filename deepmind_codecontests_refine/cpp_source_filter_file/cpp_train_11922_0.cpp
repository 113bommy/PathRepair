#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long INF = 0x3f3f3f3f;
const long long M = 1e9 + 7;
const long long N = 1e5 + 5;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(15);
  long long n, k;
  cin >> n >> k;
  long long l[n], r[n];
  for (long long i = 0; i < n; ++i) cin >> l[i] >> r[i];
  vector<long long> v;
  for (long long i = 0; i < n; ++i) v.push_back(l[i]), v.push_back(r[i]);
  sort((v).begin(), (v).end());
  map<long long, long long> ml, mr;
  for (long long i = 0; i < 2 * n; ++i) mr[v[i]] = i;
  for (long long i = 0; i < 2 * n; ++i) ml[v[2 * n - i]] = 2 * n - i;
  long long a[2 * n];
  memset(a, 0, sizeof(a));
  for (long long i = 0; i < n; ++i) a[ml[l[i]]]++, a[mr[r[i]]]--;
  partial_sum(a, a + 2 * n, a);
  vector<long long> w;
  for (long long i = 0; i < 2 * n; ++i) {
    if (w.size() % 2 == 0) {
      if (a[i] >= k) {
        w.push_back(v[i]);
      }
    } else {
      if (a[i] < k) {
        w.push_back(v[i]);
      }
    }
  }
  cout << w.size() / 2 << '\n';
  for (long long i = 0; i < w.size(); i += 2) {
    cout << w[i] << ' ' << w[i + 1] << '\n';
  }
}
