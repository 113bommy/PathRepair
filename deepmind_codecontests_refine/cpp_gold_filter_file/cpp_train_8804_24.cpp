#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const long long INF = 1LL << 62;
const long long MINF = -(1LL << 62);
template <typename T>
T getint() {
  T val = 0;
  char c;
  bool neg = false;
  while ((c = getchar()) && !(c >= '0' && c <= '9')) {
    neg |= c == '-';
  }
  do {
    val = (val * 10) + c - '0';
  } while ((c = getchar()) && (c >= '0' && c <= '9'));
  return val * (neg ? -1 : 1);
}
struct ring {
  long long a, b, h;
  bool operator<(const ring& masik) const {
    if (b == masik.b) return a < masik.a;
    return b < masik.b;
  }
};
long long tr[4 * 250001];
void maximize(int ind, int L, int R, int i, long long with) {
  if (i < L || R < i) return;
  tr[ind] = max(tr[ind], with);
  if (L != R) {
    maximize(2 * ind, L, (L + R) / 2, i, with);
    maximize(2 * ind + 1, (L + R) / 2 + 1, R, i, with);
  }
}
long long res(int ind, int L, int R, int i, int j) {
  if (j < L || R < i) return 0;
  if (i <= L && R <= j) return tr[ind];
  return max(res(2 * ind, L, (L + R) / 2, i, j),
             res(2 * ind + 1, (L + R) / 2 + 1, R, i, j));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<ring> t(n);
  vector<int> conv;
  for (int i = 0; i < n; ++i) {
    cin >> t[i].a >> t[i].b >> t[i].h;
    conv.push_back(t[i].a);
    conv.push_back(t[i].b);
  }
  sort((conv).begin(), (conv).end());
  for (int i = 0; i < n; ++i) {
    t[i].a = lower_bound((conv).begin(), (conv).end(), t[i].a) - conv.begin();
    t[i].b = lower_bound((conv).begin(), (conv).end(), t[i].b) - conv.begin();
  }
  sort((t).begin(), (t).end());
  for (auto i : t) {
    long long val = res(1, 0, 250000, i.a + 1, i.b);
    maximize(1, 0, 250000, i.b, val + i.h);
  }
  cout << res(1, 0, 250000, 0, 250000) << "\n";
  return 0;
}
