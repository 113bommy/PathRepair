#include <bits/stdc++.h>
using namespace std;
template <class T, class L>
T &smax(T &x, L y) {
  if (y > x) x = y;
  return x;
}
template <class T, class L>
T &smin(T &x, L y) {
  if (y < x) x = y;
  return x;
}
const int maxn = 2e3 + 17, inf = 1717171717;
int n, a[maxn], ans[maxn];
bool reval[maxn];
struct M {
  int sina;
  M() { sina = 0; }
} m;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], a[i] = abs(a[i]);
  while (m.sina < n) {
    int MCna = -inf, tmp = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > MCna && !reval[i]) MCna = a[i], tmp = 0;
      if (a[i] == MCna) tmp++;
    }
    m.sina += tmp;
    int badboy = 0, goodboy = 0;
    for_each(a, a + n, [MCna, &badboy](int x) {
      if (x < MCna && -MCna < x) badboy++;
    });
    for (int i = 0; i < n; i++)
      if (a[i] == MCna)
        ans[i] = badboy < goodboy ? a[i] : -a[i], reval[i] = 1;
      else if (a[i] < MCna && -MCna < a[i])
        badboy--, goodboy++;
  }
  int res = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (ans[j] < ans[i]) res++;
  cout << res << '\n';
  return 0;
}
