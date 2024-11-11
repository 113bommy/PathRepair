#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T lowbit(T n) {
  return (n ^ (n - 1)) & n;
}
template <class T>
inline int countbit(T n) {
  return (n == 0) ? 0 : (1 + countbit(n & (n - 1)));
}
template <class T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
T my_pow(T n, T p) {
  if (p == 0) return 1;
  T x = my_pow(n, p / 2);
  x = (x * x);
  if (p & 1) x = (x * n);
  return x;
}
template <class T>
T big_mod(T n, T p, T m) {
  if (p == 0) return (T)1;
  T x = big_mod(n, p / 2, m);
  x = (x * x) % m;
  if (p & 1) x = (x * n) % m;
  return x;
}
template <typename T>
T ModInverse(T n, T m) {
  return BigMod(n, m - 2, m);
}
template <class T>
T extract(string s, T ret) {
  stringstream ss(s);
  ss >> ret;
  return ret;
}
string itos(long long int n) {
  string s;
  while (n) {
    s += (n % 10 + 48);
    n /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
long long int stoi(string s) {
  long long int n = 0;
  for (__typeof(s.size()) i = 0; i < (s.size()); i++) n = n * 10 + (s[i] - 48);
  return n;
}
const long long N = 5e5 + 5, MOD = 1e9 + 7;
long long int ar[N], A[N];
long long int a, b, c, r, rr, n, m, t, ks;
string s, ss;
vector<long long int> v[400009];
int main() {
  cin >> n >> m;
  for (__typeof(n) i = 1; i <= (n); i++) {
    cin >> ar[i];
    v[ar[i]].push_back(i);
  }
  for (__typeof(40005) i = 1; i <= (40005); i++) v[i].push_back(n + 2);
  for (__typeof(n) i = 1; i <= (n); i++) {
    long long int dd =
        upper_bound(v[ar[i]].begin(), v[ar[i]].end(), i) - v[ar[i]].begin();
    A[i] = v[ar[i]][dd];
    cerr << __FUNCTION__ << ":" << 190
         << ": "
            "A[i]"
            " = "
         << A[i] << endl;
    ;
  }
  set<pair<long long int, long long int> > st;
  for (__typeof(n) i = 1; i <= (n); i++) {
    pair<long long int, long long int> P = make_pair(i * 1LL, ar[i]);
    if (st.count(P) != 0) {
      st.erase(P);
    } else
      r++;
    if (st.size() >= m) {
      st.erase(*st.rbegin());
    }
    pair<long long int, long long int> PP = make_pair(A[i], ar[i]);
    st.insert(PP);
  }
  printf("%lld", r);
  printf("\n");
  return 0;
}
