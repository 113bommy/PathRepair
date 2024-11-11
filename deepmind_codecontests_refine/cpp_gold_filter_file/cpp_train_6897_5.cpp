#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
pair<int, int> a[N], b[N], c[N];
multiset<int> L, R;
vector<pair<int, int> > S;
int sub[N], pre[N];
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  int A = 0, B = 0, C = 0;
  for (int i = 1; i <= n; i++) {
    int t, y, u;
    scanf("%d %d %d", &t, &y, &u);
    if (y == 1 && u == 1)
      a[++A] = {t, i};
    else if (y == 1)
      b[++B] = {t, i};
    else if (u == 1)
      c[++C] = {t, i};
    else
      R.insert(t), S.push_back({t, i});
  }
  sort(a + 1, a + A + 1);
  a[0] = {0, 0};
  sort(b + 1, b + B + 1);
  b[0] = {0, 0};
  sort(c + 1, c + C + 1);
  c[0] = {0, 0};
  int x = min(B, C), sum = 0;
  for (int i = B; i > x; i--) R.insert(b[i].first);
  for (int i = C; i > x; i--) R.insert(c[i].first);
  for (int i = 0; i <= x; i++) sub[i] = 2e9 + 1;
  for (int i = 1; i <= x; i++) pre[i] = pre[i - 1] + b[i].first + c[i].first;
  for (int i = x; i >= 0; i--) {
    bool f = true;
    if (2 * i > m) f = false;
    int x = m - 2 * i;
    if (k > i) {
      if (k - i > A) f = false;
      x -= k - i;
    }
    if (x < 0) f = false;
    if (L.size() + R.size() < x) f = false;
    if (f) {
      while (L.size() < x) {
        sum += *R.begin();
        L.insert(*R.begin());
        R.erase(R.begin());
      }
      while (L.size() > x) {
        sum -= *L.rbegin();
        R.insert(*L.rbegin());
        L.erase(--L.end());
      }
      sub[i] = sum + pre[i];
    }
    if (i == 0) break;
    if (R.size() && b[i].first >= *R.begin())
      R.insert(b[i].first);
    else
      L.insert(b[i].first), sum += b[i].first;
    if (R.size() && c[i].first >= *R.begin())
      R.insert(c[i].first);
    else
      L.insert(c[i].first), sum += c[i].first;
  }
  int ans = 2e9 + 1, pos, now = 0;
  for (int i = 0; i <= A; i++) {
    now += a[i].first;
    if (i > m) break;
    if (i >= k) {
      int x = m - i;
      if (L.size() + R.size() < x) continue;
      while (L.size() < x) {
        sum += *R.begin();
        L.insert(*R.begin());
        R.erase(R.begin());
      }
      while (L.size() > x) {
        sum -= *L.rbegin();
        R.insert(*L.rbegin());
        L.erase(--L.end());
      }
      int res = sum + now;
      if (ans > res) ans = res, pos = i;
    } else {
      if (k - i > min(B, C)) continue;
      long long res = now + 0ll + sub[k - i];
      if (ans > res) ans = res, pos = i;
    }
  }
  if (ans > 2e9) {
    puts("-1");
    return 0;
  }
  printf("%d\n", ans);
  vector<int> V;
  for (int i = 1; i <= pos; i++) V.push_back(a[i].second);
  for (int i = 1; i <= k - pos; i++)
    V.push_back(b[i].second), V.push_back(c[i].second);
  for (int i = max(1, k - pos + 1); i <= B; i++) S.push_back(b[i]);
  for (int i = max(1, k - pos + 1); i <= C; i++) S.push_back(c[i]);
  sort(S.begin(), S.end());
  for (int i = 0; i < m - pos - max(0, k - pos) * 2; i++)
    V.push_back(S[i].second);
  int siz = V.size();
  for (int i = 0; i < siz; i++) printf("%d%c", V[i], i == siz - 1 ? '\n' : ' ');
  return 0;
}
