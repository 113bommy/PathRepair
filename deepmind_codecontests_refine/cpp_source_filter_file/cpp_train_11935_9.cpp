#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double tiaohe = 0.57721566490153286060651209;
long long oula(long long x) {
  long long res = x;
  for (register int i = 2; i <= x / i; ++i) {
    if (x % i == 0) {
      res = res / i * (i - 1);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) res = res / x * (x - 1);
  return res;
}
long long quickmod(long long a, long long n, long long m) {
  long long s = 1;
  while (n) {
    if (n & 1) {
      s = s * a % m;
    }
    a = (a * a) % m;
    n = n / 2;
  }
  return s;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void ex_gcd(long long a, long long b, long long &x, long long &y,
            long long &d) {
  if (!b) {
    d = a, x = 1, y = 0;
  } else {
    ex_gcd(b, a % b, y, x, d);
    y -= x * (a / b);
  }
}
long long inv(long long t, long long p) {
  long long d, x, y;
  ex_gcd(t, p, x, y, d);
  return d == 1 ? (x % p + p) % p : -1;
}
bool isPrime(long long x) {
  if (x == 2) return true;
  if (x % 2 == 0) return false;
  for (long long i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
double eqa = (1 + sqrt(5.0)) / 2.0;
const int N = 6e5 + 5;
struct node {
  int w;
  int ti;
  int id;
  bool operator<(const node b) const {
    if (this->ti == b.ti) return this->w > b.w;
    return this->ti < b.ti;
  }
} a[N];
struct node2 {
  int w;
  int ti;
  int id;
  bool operator<(const node2 b) const {
    if (this->w == b.w) return this->ti > b.ti;
    return this->w < b.w;
  }
};
int main() {
  int n, time;
  while (cin >> n >> time) {
    multiset<node> st;
    for (register int i = 1; i <= n; ++i) {
      scanf("%d%d", &a[i].w, &a[i].ti);
      a[i].id = i;
      st.insert(a[i]);
    }
    node2 b;
    multiset<node2> st2;
    while (1) {
      auto it = st.begin();
      if (time >= it->ti) {
        time -= it->ti;
        b.id = it->id, b.ti = it->ti, b.w = it->w;
        st.erase(it);
        st2.insert(b);
      } else
        break;
      while (st2.begin()->w < st2.size()) {
        time += st2.begin()->w;
        st2.erase(st2.begin());
      }
      if (st.empty()) break;
    }
    cout << st2.size() << endl << st2.size() << endl;
    for (auto I : st2) cout << I.id << " ";
    puts("");
  }
  return 0;
}
