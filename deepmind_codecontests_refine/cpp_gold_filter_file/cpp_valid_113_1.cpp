#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long INF = 5e18;
int inf = 1e9;
void d_err() { cerr << endl; }
template <typename H, typename... T>
void d_err(H h, T... t) {
  cerr << h << " ";
  d_err(t...);
}
template <typename T>
void print(T x) {
  cout << x << "\n";
}
template <typename T>
void print(vector<T>& x) {
  int N = x.size();
  for (long long i = (0); i < (N); ++i) {
    if (i > 0) cout << " ";
    cout << x[i];
  }
  cout << "\n";
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = (0); i < (n); ++i) cin >> a[i];
  ;
  sort((a).begin(), (a).end());
  long long s = accumulate((a).begin(), (a).end(), 0LL);
  int m;
  cin >> m;
  while (m--) {
    long long x, y;
    cin >> x >> y;
    long long a1 = INF, a2 = INF;
    auto it = lower_bound((a).begin(), (a).end(), x);
    if (it != a.end()) {
      a1 = max(0LL, y - s + *it);
    }
    if (it != a.begin()) {
      it--;
      a2 = x - *it;
      a2 += max(0LL, y - s + *it);
    }
    print(min(a1, a2));
  }
}
