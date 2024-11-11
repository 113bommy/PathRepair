#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using pdd = pair<double, double>;
void cind(int &a) { scanf("%d", &a); }
void cinll(ll &a) { scanf("%lld", &a); }
void cinf(double &a) { scanf("%lf", &a); }
void printd(const int &a) { printf("%d ", a); }
void printll(const ll &a) { printf("%I64d ", a); }
void printf(const double &a) { printf("%.10f ", a); }
template <typename T>
void prvec(vector<T> v) {
  for (auto a : v) {
    cout << a << " ";
  }
}
inline void get(ll &a) { scanf("%I64d", &a); }
template <typename T>
void getvec(vector<T> &v, int n) {
  v.resize(n);
  for (auto &a : v) {
    get(a);
  }
}
vector<ll> used(1e5 + 10, 0);
bool is_cycle = false;
using ull = unsigned long long;
int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll res = 0;
  ll mn = min(min(a, c), d);
  res += mn * 256;
  a -= mn;
  res += min(a, b) * 32;
  cout << res << endl;
}
