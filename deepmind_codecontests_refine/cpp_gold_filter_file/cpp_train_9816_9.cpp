#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &str, vector<T> &a) {
  for (auto &i : a) {
    str << i << " ";
  }
  return str;
}
template <class T>
istream &operator>>(istream &str, vector<T> &a) {
  for (auto &i : a) {
    str >> i;
  }
  return str;
}
template <class T>
ostream &operator<<(ostream &str, pair<T, T> &a) {
  str << a.first << " " << a.second;
  return str;
}
template <class T>
istream &operator>>(istream &str, pair<T, T> &a) {
  str >> a.first >> a.second;
  return str;
}
void solve();
signed main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(20);
  solve();
  return 0;
}
const long long MAXN = 1e6 + 10, INF = 1e18 + 10;
vector<long long> factorial;
long long N = 15;
vector<long long> gen(long long first) {
  vector<long long> a(N);
  for (long long i = 0; i < N; ++i) {
    a[i] = i;
  }
  set<long long> se;
  for (auto it : a) {
    se.insert(it);
  }
  long long n = a.size();
  for (long long i = 0; i < n; ++i) {
    for (auto el : se) {
      if (first - factorial[n - i - 1] > 0) {
        first -= factorial[n - i - 1];
      } else {
        a[i] = el;
        se.erase(el);
        break;
      }
    }
  }
  return a;
}
void solve() {
  long long n, q;
  cin >> n >> q;
  vector<long long> ps(n + 1);
  vector<long long> a(n + 1);
  for (long long i = 1; i <= n; ++i) {
    a[i] = i;
  }
  ps[1] = 1;
  for (long long i = 2; i <= n; ++i) {
    ps[i] = ps[i - 1] + i;
  }
  N = min(n, N);
  factorial.resize(21);
  factorial[0] = 1;
  for (long long i = 1; i <= 20; ++i) {
    factorial[i] = factorial[i - 1] * i;
  }
  long long add = n - N + 1;
  vector<long long> dp(n + 1);
  long long sum = 0;
  for (long long _ = 0; _ < q; ++_) {
    long long type;
    cin >> type;
    if (type == 1) {
      long long l, r;
      cin >> l >> r;
      cout << ps[r] - ps[l - 1] << '\n';
    } else {
      long long first;
      cin >> first;
      sum += first;
      vector<long long> p = gen(sum + 1);
      for (auto &it : p) {
        it += add;
      }
      for (long long i = n - N + 1; i <= n; ++i) {
        a[i] = p[i - (n - N + 1)];
      }
      for (long long i = n - N + 1; i <= n; ++i) {
        ps[i] = ps[i - 1] + a[i];
      }
    }
  }
}
