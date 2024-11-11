#include <bits/stdc++.h>
using namespace std;
template <typename T>
void Debug(T begin, T end);
int si();
long long sl();
string ss(int);
double sf();
long double slf();
void pi(int, char = '\n');
void pl(long long, char = '\n');
void pf(double, char = '\n');
void plf(long double, char = '\n');
void ps(string, char = '\n');
long long russian(long long, long long, long long);
long long fast_power(long long, long long, long long);
long long slow_power(long long, long long, long long);
long long gcd(long long, long long);
long long lcm(long long, long long);
const int INF = 1e9;
const long long LINF = 1e18;
const int N = 2e5 + 7, TREE = (1 << 19) + 7;
pair<int, int> A[N];
pair<pair<int, int>, int> Q[N];
int ans[N], ori[N], S[TREE];
int p = 1;
void add(int v) {
  v += p;
  ++S[v];
  v >>= 1;
  while (v) {
    S[v] = S[v + v] + S[v + v + 1];
    v >>= 1;
  }
}
int answer(int pos) {
  int v = 1;
  while (v < p) {
    v <<= 1;
    if (pos > S[v]) pos -= S[v++];
  }
  return ori[v - p];
}
int main() {
  int n = si();
  for (int i = 0; i < n; ++i) {
    ori[i] = si();
    A[i].first = -ori[i];
    A[i].second = i;
  }
  sort(A, A + n);
  while (p < n) p <<= 1;
  int q = si();
  for (int i = 0; i < q; ++i) {
    Q[i].first.first = si();
    Q[i].first.second = si();
    Q[i].second = i;
  }
  sort(Q, Q + q);
  int it = 0;
  for (int i = 0; i < q; ++i) {
    auto [k, pos] = Q[i].first;
    while (it < k) add(A[it++].second);
    ans[Q[i].second] = answer(pos);
  }
  for (int i = 0; i < q; ++i) pi(ans[i]);
  return 0;
}
template <typename T>
void Debug(T begin, T end) {
  printf("\nDEBUG:\n");
  while (begin != end) printf("%d ", *begin), begin++;
  printf("\n\n");
}
template <typename T>
T scanf_t(string s) {
  T a;
  scanf(s.c_str(), &a);
  return a;
}
template <typename T>
void printf_t(T a, string s, char end_l) {
  s.push_back(end_l);
  printf(s.c_str(), a);
}
int si() { return scanf_t<int>("%d"); }
long long sl() { return scanf_t<long long>("%lld"); }
double sf() { return scanf_t<double>("%f"); }
long double slf() { return scanf_t<long double>("%Lf"); }
void pi(int a, char end_l) { printf_t<int>(a, "%d", end_l); }
void pl(long long a, char end_l) { printf_t<long long>(a, "%lld", end_l); }
void pf(double a, char end_l) { printf_t<double>(a, "%lf", end_l); }
void plf(long double a, char end_l) { printf_t<long double>(a, "%Lf", end_l); }
void ps(string a, char end_l) {
  string s = "%s";
  s.push_back(end_l);
  printf(s.c_str(), a.c_str());
}
string ss(int NN) {
  char T[NN];
  scanf("%s", T);
  return (string)T;
}
long long fast_power(long long a, long long k, long long m) {
  long long r = 1LL;
  while (k) {
    if (k & 1LL) r = (r * a) % m;
    a = (a * a) % m;
    k >>= 1LL;
  }
  return r;
}
long long slow_power(long long a, long long k, long long m) {
  long long r = 1LL;
  while (k) {
    if (k & 1LL) r = russian(r, a, m);
    a = russian(a, a, m);
    k >>= 1LL;
  }
  return r;
}
long long russian(long long a, long long k, long long m) {
  long long r = 0LL;
  while (k) {
    if (k & 1LL) r = (r + a) % m;
    a = (a + a) % m;
    k >>= 1LL;
  }
  return r;
}
long long gcd(long long a, long long b) {
  while (b) swap(a %= b, b);
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
