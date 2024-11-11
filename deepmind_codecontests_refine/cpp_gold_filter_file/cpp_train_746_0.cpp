#include <bits/stdc++.h>
using namespace std;
const int OO = 1e9;
const long long INF = 1e18;
const int irand(int lo, int hi) {
  return ((double)rand() / (RAND_MAX + 1.0)) * (hi - lo + 1) + lo;
}
const long long lrand(long long lo, long long hi) {
  return ((double)rand() / (RAND_MAX + 1.0)) * (hi - lo + 1) + lo;
}
template <typename T>
T getnum() {
  int sign = 1;
  T ret = 0;
  char c;
  do {
    c = getchar();
  } while (c == ' ' || c == '\n');
  if (c == '-')
    sign = -1;
  else
    ret = c - '0';
  while (1) {
    c = getchar();
    if (c < '0' || c > '9') break;
    ret = 10 * ret + c - '0';
  }
  return sign * ret;
}
inline void ini(int& x) { x = getnum<int>(); }
inline void scani(int& x) { scanf("%d", &x); }
const int N = 1e6 + 5;
int n;
long long k;
bool used[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(10);
  cin >> n >> k;
  long long lb = 0, ub = 0;
  for (int i = 1; i <= n; i += 1) {
    lb += i;
    ub += max(i, n - i + 1);
  }
  if (k < lb) {
    cout << -1 << '\n';
  } else {
    cout << min(k, ub) << '\n';
    for (int i = 1; i <= n; i += 1) cout << i << " ";
    cout << '\n';
    k -= lb;
    for (int i = 1; i <= n / 2; i += 1) {
      int t = n - i + 1;
      if (t - i > k) {
        t = k + i;
        cout << t << " ";
        used[t] = true;
        break;
      } else {
        cout << t << " ";
        k -= t - i;
        used[t] = true;
      }
    }
    for (int i = 1; i <= n; i += 1) {
      if (!used[i]) cout << i << " ";
    }
    cout << '\n';
  }
  return 0;
}
