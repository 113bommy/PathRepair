#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void input(T &x) {
  register char c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
inline long long bigmod(long long p, long long e, long long M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
const int N = 1001;
int n, m, k;
int day[10004];
int main() {
  cin >> n >> m >> k;
  vector<int> v;
  int need = 0;
  for (int i = 1; i < n + m; i++) {
    if (day[i] < k) {
      need += k - day[i];
      for (int j = 0; j < k - day[i]; j++) v.push_back(i);
      for (int j = i; j <= n + i - 1; j++) day[j] = k;
    }
    if (day[i + 1] == 0) {
      need++;
      v.push_back(i);
      for (int j = i; j <= n + i - 1; j++) day[j]++;
    }
  }
  cout << need << endl;
  for (auto x : v) cout << x << " ";
  return 0;
}
