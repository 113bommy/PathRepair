#include <bits/stdc++.h>
const int MAXN = 1000 + 5;
const int MAXM = 1e6 + 5;
int n, m;
int a[MAXN], b[MAXN];
std::vector<int> L, R, U, D;
std::bitset<MAXM> f[MAXN];
inline bool work(int a[], std::vector<int> &v1, std::vector<int> &v2) {
  f[0][0] = 1;
  v1.clear();
  v2.clear();
  int sm = 0;
  for (int i = 1; i <= n; ++i) f[i] = f[i - 1] | (f[i - 1] << a[i]), sm += a[i];
  if (sm & 1) return 0;
  sm >>= 1;
  if (!f[n][sm]) return 0;
  for (int i = n; i >= 1; --i) {
    if (sm - a[i] >= 0 && f[i - 1][sm - a[i]])
      v1.push_back(a[i]), sm -= a[i];
    else
      v2.push_back(a[i]);
  }
  if (v1.size() > v2.size()) std::swap(v1, v2);
  return 1;
}
inline void Solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf("%d", b + i);
  if (n != m) {
    puts("No");
    return;
  }
  bool flag = 1;
  flag &= work(a, R, L);
  flag &= work(b, U, D);
  if (!flag) {
    puts("No");
    return;
  }
  puts("Yes");
  if (R.size() > U.size()) {
    std::swap(R, L);
    std::swap(U, D);
  }
  std::sort(R.begin(), R.end());
  std::sort(U.begin(), U.end());
  std::reverse(R.begin(), R.end());
  std::vector<std::pair<int, int> > ans, ansr;
  ans.push_back(std::make_pair(0, 0));
  for (int i = 0; i <= (int)std::min(R.size(), U.size()) - 1; ++i) {
    int x = ans.back().first, y = ans.back().second;
    x += R[i];
    ans.push_back(std::make_pair(x, y));
    y += U[i];
    ans.push_back(std::make_pair(x, y));
  }
  std::sort(L.begin(), L.end());
  std::sort(D.begin(), D.end());
  std::reverse(D.begin(), D.end());
  ansr.push_back(std::make_pair(0, 0));
  for (int i = 0; i <= (int)std::min(L.size(), D.size()) - 1; ++i) {
    int x = ansr.back().first, y = ansr.back().second;
    y += D[i];
    ansr.push_back(std::make_pair(x, y));
    x += L[i];
    ansr.push_back(std::make_pair(x, y));
  }
  std::vector<int> h, l;
  int x = ans.back().first, y = ans.back().second;
  if (R.size() < U.size())
    for (int i = std::min(R.size(), U.size()); i <= (int)U.size() - 1; ++i)
      l.push_back(U[i]);
  else
    for (int i = std::min(R.size(), U.size()); i <= (int)R.size() - 1; ++i)
      h.push_back(R[i]);
  if (L.size() < D.size())
    for (int i = std::min(L.size(), D.size()); i <= (int)D.size() - 1; ++i)
      l.push_back(-D[i]);
  else
    for (int i = std::min(L.size(), D.size()); i <= (int)L.size() - 1; ++i)
      h.push_back(-L[i]);
  assert(h.size() == l.size());
  if (R.size() < U.size() || 1) {
    for (int i = 0; i <= (int)h.size() - 1; ++i) {
      int x = ans.back().first, y = ans.back().second;
      x += h[i];
      ans.push_back(std::make_pair(x, y));
      y += l[i];
      ans.push_back(std::make_pair(x, y));
    }
  } else {
    assert(L.size() <= D.size());
    std::cerr << "ans.back().fi" << '=' << ans.back().first << std::endl;
    std::cerr << "ans.back().se" << '=' << ans.back().second << std::endl;
    std::cerr << "ansr.back().fi" << '=' << ansr.back().first << std::endl;
    std::cerr << "ansr.back().se" << '=' << ansr.back().second << std::endl;
    for (auto x : l) std::cerr << "x" << '=' << x << std::endl;
    for (int i = 0; i <= (int)h.size() - 1; ++i) {
      int x = ansr.back().first, y = ansr.back().second;
      y -= l[i];
      ansr.push_back(std::make_pair(x, y));
      x -= h[i];
      ansr.push_back(std::make_pair(x, y));
    }
  }
  assert(ansr.back() == ans.back());
  ansr.pop_back();
  std::reverse(ansr.begin(), ansr.end());
  std::reverse(ans.begin(), ans.end());
  ans.pop_back();
  std::reverse(ans.begin(), ans.end());
  int t = ans.size();
  for (auto x : ansr) ans.push_back(x);
  for (auto x : ans) printf("%d %d\n", x.first, x.second);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) Solve();
  return 0;
}
