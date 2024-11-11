#include <bits/stdc++.h>
using namespace std;
template <class T>
inline string itos(T n) {
  return (n) < 0    ? "-" + itos(-(n))
         : (n) < 10 ? (string)("") + (char)('0' + (n))
                    : itos((n) / 10) + itos((n) % 10);
}
int N, L, a[60], b[60], c[60];
bool check(void) {
  int i;
  for ((i) = 0; (i) < (int)(N); (i)++) c[i] = b[N - 1 - i];
  if (c[0] == 1)
    for ((i) = 0; (i) < (int)(N); (i)++) c[i] = 1 - c[i];
  for ((i) = 0; (i) < (int)(N); (i)++)
    if (b[i] < c[i])
      return true;
    else if (b[i] > c[i])
      return false;
  return true;
}
long long func2(int n) {
  return ((1ll << n) + (1ll << ((n + 1) / 2)) + (1ll << n) +
          ((n % 2 == 0) ? (1ll << ((n + 1) / 2)) : 0)) /
         2;
}
long long func(void) {
  int i;
  if (a[0] == 1) return 0;
  long long tmp = 0;
  for ((i) = 0; (i) < (int)(min(L, N - L)); (i)++)
    if (i != 0) tmp = tmp * 2 + (1 - a[i]);
  if (L * 2 <= N) {
    double d = 2.0 * tmp * (1ll << (N - 2 * L)) + func2(N - 2 * L);
    if (d > (1ll << 60)) return (1ll << 60);
    return 2 * tmp * (1ll << (N - 2 * L)) + func2(N - 2 * L);
  }
  long long ans = tmp * 2;
  if (L == N) {
    for ((i) = 0; (i) < (int)(N); (i)++) b[i] = a[i];
    if (check()) ans++;
  } else {
    for ((i) = 0; (i) < (int)(N); (i)++) b[i] = ((i < L) ? a[i] : a[N - 1 - i]);
    if (check()) ans++;
    for ((i) = 0; (i) < (int)(N); (i)++)
      b[i] = ((i < L) ? a[i] : (1 - a[N - 1 - i]));
    if (check()) ans++;
  }
  return ans;
}
bool dfs(long long K) {
  if (L == N) return true;
  L++;
  a[L - 1] = 0;
  long long tmp = func();
  if (K <= tmp) return dfs(K);
  a[L - 1] = 1;
  long long tmp2 = func();
  if (K <= tmp + tmp2) return dfs(K - tmp);
  return false;
}
int main(void) {
  int i;
  long long K;
  cin >> N >> K;
  K++;
  if (!dfs(K))
    cout << -1 << endl;
  else {
    for ((i) = 0; (i) < (int)(N); (i)++) cout << a[i];
    cout << endl;
  }
  return 0;
}
