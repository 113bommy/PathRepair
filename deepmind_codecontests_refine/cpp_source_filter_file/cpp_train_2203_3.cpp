#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
bool parity(int n) { return !(n & 1); }
bool is2(int n) { return n & (n - 1) == 0; }
template <typename T>
T sqr(T a) {
  return a * a;
}
template <typename T>
T binpow(T n, T s, int base) {
  if (s <= 0) return 1LL;
  if (s % 2 == 0) {
    T b = binpow(n, s / 2, base);
    return (1LL * b * b) % base;
  } else
    return (1LL * binpow(n, s - 1, base) * n) % base;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> mas(n + 1);
    for (int i = 1; i <= n; ++i) cin >> mas[i];
    int curMin = 1e9 + 6, curAns = 0, ans = 0;
    for (int i = 1; i + k < mas.size(); i++) {
      curAns = (mas[i] + mas[i + k]) / 2;
      if (max(abs(mas[i] - curAns), abs(mas[i + k] - curAns)) < curMin) {
        curMin = max(abs(mas[i] - curAns), abs(mas[i + k] - curAns));
        ans = curAns;
      }
    }
    cout << ans;
  }
  return 0;
}
