#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
inline void relax_min(T &a, U b) {
  a = min(a, b);
}
template <class T, class U>
inline void relax_max(T &a, U b) {
  a = max(a, b);
}
template <typename T>
inline bool updmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool updmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <class T, class U>
istream &operator>>(istream &in, pair<T, U> &a) {
  in >> a.first >> a.second;
  return in;
}
template <class T, class U>
ostream &operator<<(ostream &out, const pair<T, U> &a) {
  out << a.first << ' ' << a.second;
  return out;
}
template <class T>
istream &operator>>(istream &in, vector<T> &a) {
  for (decltype(0)((i)) = (0); ((i)) < ((((int)(a).size()))); ++((i)))
    in >> a[i];
  return in;
}
template <class T>
ostream &operator<<(ostream &out, const vector<T> &a) {
  for (decltype(0)((i)) = (0); ((i)) < ((((int)(a).size()))); ++((i)))
    out << a[i] << ' ';
  return out;
}
int next_int() {
  int(tmp);
  scanf("%d", &(tmp));
  return tmp;
}
long long next_ll() {
  long long(tmp);
  scanf("%lld", &(tmp));
  return tmp;
}
long long modPow(long long a, long long b, long long MOD) {
  long long ret = 1;
  for (; b; b >>= 1) {
    if (b & 1)
      ret = ((((((long long)(ret) * (long long)(a))) % ((MOD))) + ((MOD))) %
             ((MOD)));
    a = ((((((long long)(a) * (long long)(a))) % ((MOD))) + ((MOD))) % ((MOD)));
  }
  return ret;
}
const long long EXACTLY_ONE_HUNDRED = 100;
const long long EXACTLY_ONE_THOUSAND = 1000;
const long long EXACTLY_ONE_MILLION = 1000 * 1000;
const long long EXACTLY_ONE_BILLION =
    EXACTLY_ONE_THOUSAND * EXACTLY_ONE_MILLION;
const int MAXN1 = (int)(EXACTLY_ONE_HUNDRED * EXACTLY_ONE_THOUSAND) + 3;
const int MAXN2 = (int)(2 * EXACTLY_ONE_HUNDRED * EXACTLY_ONE_THOUSAND) + 3;
const int MAXN3 = (int)(3 * EXACTLY_ONE_HUNDRED * EXACTLY_ONE_THOUSAND) + 3;
const int MAXN4 = (int)(4 * EXACTLY_ONE_HUNDRED * EXACTLY_ONE_THOUSAND) + 3;
const int MAXN5 = (int)(5 * EXACTLY_ONE_HUNDRED * EXACTLY_ONE_THOUSAND) + 3;
const int MAXN = MAXN3;
const int INF = (int)EXACTLY_ONE_BILLION + 7;
const int INF2 = 1 << 30;
const long long INFLL = 4LL * EXACTLY_ONE_BILLION * EXACTLY_ONE_BILLION + 7;
const long long INFLL2 = 1LL << 60;
const long double Pi = acos(-1.0);
const long double EPS = 1e-7;
const int MOD = (int)EXACTLY_ONE_BILLION + 7;
int main() {
  int(n);
  scanf("%d", &(n));
  vector<int> l(n), r(n);
  for (decltype(0)((IT_FOR_SCANNING)) = (0); ((IT_FOR_SCANNING)) < ((((n))));
       ++((IT_FOR_SCANNING)))
    scanf("%d%d", &(((l))[IT_FOR_SCANNING]), &(((r))[IT_FOR_SCANNING]));
  vector<int> p(n);
  for (decltype(0)((i)) = (0); ((i)) < ((n)); ++((i))) {
    p[i] = i;
  }
  auto cmp = [&l, &r](int i, int j) { return l[i] < l[j]; };
  sort((p).begin(), (p).end(), cmp);
  int last1 = 0, last2 = 0;
  for (decltype(0)((I)) = (0); ((I)) < ((n)); ++((I))) {
    int i = p[I];
    if (l[i] > last1) {
      last1 = r[i];
    } else if (l[i] > last2) {
      last2 = r[i];
    } else {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
