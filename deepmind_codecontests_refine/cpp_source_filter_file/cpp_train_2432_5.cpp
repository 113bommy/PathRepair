#include <bits/stdc++.h>
using namespace std;
template <class _T>
inline _T sqr(const _T& x) {
  return x * x;
}
template <class _T>
inline string tostr(const _T& a) {
  ostringstream os("");
  os << a;
  return os.str();
}
const long double PI = 3.1415926535897932384626433832795L;
const long double EPS = 1e-11;
char TEMPORARY_CHAR;
const unsigned long long INF = 1e17;
const int N = 1 << 16;
inline void input(int& a) {
  a = 0;
  while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') &&
         (TEMPORARY_CHAR != '-')) {
  }
  char neg = 0;
  if (TEMPORARY_CHAR == '-') {
    neg = 1;
    TEMPORARY_CHAR = getchar();
  }
  while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {
    a = (a << 3) + (a << 1) + TEMPORARY_CHAR - '0';
    TEMPORARY_CHAR = getchar();
  }
  if (neg) a = -a;
}
inline int nxt() {
  int(ret);
  input((ret));
  ;
  return ret;
}
unsigned long long powi(int t, int j) {
  if (j == 0) return 1;
  if (j % 2 == 0) {
    return powi(t, j / 2) * powi(t, j / 2);
  } else {
    return powi(t, j / 2) * powi(t, j / 2) * t;
  }
}
int main() {
  int(n);
  input((n));
  ;
  vector<int> a(n);
  for (int i = 0; i < (int)(n); i++) {
    a[i] = nxt();
  }
  sort((a).begin(), (a).end());
  vector<unsigned long long> sum(n);
  sum[0] = a[0];
  for (int i = 1; i < n; ++i) {
    sum[i] = sum[i - 1] + (unsigned long long)a[i];
  }
  int(q);
  input((q));
  ;
  int t;
  map<int, unsigned long long> b;
  unsigned long long ans = 0;
  for (int i = 0; i < (int)(q); i++) {
    ans = 0;
    t = nxt();
    if (b.find(t) != b.end()) {
      cout << b[t] << " ";
    } else {
      int id = 0;
      for (int j = 0; id + powi(t, j) <= n - 1; ++j) {
        ans += sum[n - 1 - id - pow(t, j)];
        id += pow(t, j);
      }
      cout << ans << " ";
      b.insert(pair<int, unsigned long long>(t, ans));
    }
  }
  cout << endl;
  return 0;
}
