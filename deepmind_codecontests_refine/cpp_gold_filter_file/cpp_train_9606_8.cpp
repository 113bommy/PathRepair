#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
const int MOD2 = 998244353;
const int INF = 1 << 30;
const ll INF2 = (ll)1 << 60;
void scan(int& a) { scanf("%d", &a); }
void scan(long long& a) { scanf("%lld", &a); }
template <class T, class L>
void scan(pair<T, L>& p) {
  scan(p.first);
  scan(p.second);
}
template <class T>
void scan(T& a) {
  cin >> a;
}
template <class T>
void scan(vector<T>& vec) {
  for (auto&& it : vec) scan(it);
}
void in() {}
template <class Head, class... Tail>
void in(Head& head, Tail&... tail) {
  scan(head);
  in(tail...);
}
void print(const int& a) { printf("%d", a); }
void print(const long long& a) { printf("%lld", a); }
void print(const double& a) { printf("%.15lf", a); }
template <class T, class L>
void print(const pair<T, L>& p) {
  print(p.first);
  putchar(' ');
  print(p.second);
}
template <class T>
void print(const T& a) {
  cout << a;
}
template <class T>
void print(const vector<T>& vec) {
  if (vec.empty()) return;
  print(vec[0]);
  for (auto it = vec.begin(); ++it != vec.end();) {
    putchar(' ');
    print(*it);
  }
}
void out() { putchar('\n'); }
template <class T>
void out(const T& t) {
  print(t);
  putchar('\n');
}
template <class Head, class... Tail>
void out(const Head& head, const Tail&... tail) {
  print(head);
  putchar(' ');
  out(tail...);
}
template <class T>
void dprint(const T& a) {
  cerr << a;
}
template <class T>
void dprint(const vector<T>& vec) {
  if (vec.empty()) return;
  cerr << vec[0];
  for (auto it = vec.begin(); ++it != vec.end();) {
    cerr << " " << *it;
  }
}
void debug() { cerr << endl; }
template <class T>
void debug(const T& t) {
  dprint(t);
  cerr << endl;
}
template <class Head, class... Tail>
void debug(const Head& head, const Tail&... tail) {
  dprint(head);
  cerr << " ";
  debug(tail...);
}
ll intpow(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b /= 2;
  }
  return ans;
}
ll modpow(ll a, ll b, ll p) {
  ll ans = 1;
  while (b) {
    if (b & 1) (ans *= a) %= p;
    (a *= a) %= p;
    b /= 2;
  }
  return ans;
}
ll updivide(ll a, ll b) {
  if (a % b == 0)
    return a / b;
  else
    return (a / b) + 1;
}
vector<vector<long long int>> combination_calc(5000,
                                               vector<long long int>(5000, -1));
long long int combination2(long long int n, long long int k) {
  if (combination_calc[n][k] != -1) {
    return combination_calc[n][k];
  } else if (k == 0) {
    combination_calc[n][0] = 1;
    return 1;
  } else if (k == n) {
    combination_calc[n][n] = 1;
    return 1;
  } else if (n < 5000) {
    combination_calc[n][k] =
        combination2(n - 1, k - 1) + combination2(n - 1, k);
    return combination_calc[n][k];
  } else {
    return combination2(n - 1, k - 1) + combination2(n - 1, k);
  }
}
int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    int n;
    in(n);
    vector<int> vec(n), index;
    in(vec);
    sort(vec.begin(), vec.end());
    ll d = 1;
    int m = 0;
    for (int i = 0; i < n; i++) {
      if (vec[i] < d) {
        m++;
      } else {
        index.push_back(m);
        while (vec[i] >= d) {
          d *= 2;
        }
        m = 1;
      }
    }
    index.push_back(m);
    ll ans = 0;
    for (int i = 0; i < index.size(); i++) {
      if (index[i] >= 2) {
        ans += (ll)index[i] * (index[i] - 1) / 2;
      }
    }
    out(ans);
  }
}
