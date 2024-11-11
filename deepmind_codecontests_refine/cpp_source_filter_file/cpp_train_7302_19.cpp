#include <bits/stdc++.h>
using namespace std;
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return __builtin_popcountll(s);
}
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
int n;
long long a[1000025], mask[1000025], last[1000025];
void sol() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  long long sum = 0;
  for (int i = (1); i <= (n); ++i) {
    cin >> a[i] >> mask[i];
    sum += a[i];
    for (int j = 0; j < (64); ++j)
      if (getbit(mask[i], j)) last[i] = j;
  }
  if (sum > 0) {
    for (int i = (1); i <= (n); ++i) a[i] = -a[i];
  }
  long long res = 0;
  for (int t = 0; t < (64); ++t) {
    sum = 0;
    for (int i = (1); i <= (n); ++i)
      if (last[i] == t) {
        if (cntbit(a[i] & res) & 1)
          sum -= a[i];
        else
          sum += a[i];
      }
    if (sum < 0) res = onbit(res, t);
  }
  cout << res << endl;
}
int main() {
  sol();
  return 0;
}
