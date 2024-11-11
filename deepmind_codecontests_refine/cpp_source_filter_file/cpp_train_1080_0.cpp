#include <bits/stdc++.h>
using namespace std;
template <class P, class Q>
void smin(P &a, Q b) {
  if (b < a) a = b;
}
template <class P, class Q>
void smax(P &a, Q b) {
  if (b > a) a = b;
}
template <class P, class Q>
bool in(const P &a, const Q &b) {
  return a.find(b) != a.end();
}
const int MAXN = 101 * 1000;
const int SZ = 3;
vector<int> g[SZ];
int n, arr[MAXN], ops = 0;
long long sum[SZ], co_sum[SZ];
void recalc(int i) {
  sum[i] = 0;
  co_sum[i] = 0;
  for (int j = (0); j < int(((int)(g[i]).size())); ++j) {
    sum[i] += g[i][j];
    co_sum[i] += 2LL * j * g[i][j];
  }
}
void rebuild() {
  vector<int> tmp;
  for (int i = (0); i < int(SZ); ++i) {
    for (int j = (0); j < int(((int)(g[i]).size())); ++j)
      tmp.push_back(g[i][j]);
    g[i].clear();
  }
  int pt = 0;
  for (int i = (0); i < int(((int)(tmp).size())); ++i) {
    g[pt].push_back(tmp[i]);
    if ((i + 1) % SZ == 0) pt++;
  }
  for (int i = (0); i < int(SZ); ++i) recalc(i);
}
void add(int x) {
  if (ops % SZ == 0) rebuild();
  ops++;
  int b = 0;
  for (int i = (0); i < int(SZ); ++i)
    if (!g[i].empty() && g[i][0] < x) b = i;
  int pt = ((int)(g[b]).size());
  g[b].push_back(x);
  while (pt && g[b][pt] < g[b][pt - 1]) swap(g[b][pt - 1], g[b][pt]), pt--;
  recalc(b);
}
void del(int x) {
  if (ops % SZ == 0) rebuild();
  ops++;
  for (int i = (0); i < int(SZ); ++i)
    if (!g[i].empty() && g[i][0] <= x && x <= g[i].back() &&
        binary_search((g[i]).begin(), (g[i]).end(), x)) {
      g[i].erase(find((g[i]).begin(), (g[i]).end(), x));
      recalc(i);
      break;
    }
}
long long query(int x, int y) {
  if (ops % SZ == 0) rebuild();
  ops++;
  long long tot = 0, co = 0, cnt = 0, all_sum = 0;
  for (int i = (0); i < int(SZ); ++i)
    if (!g[i].empty()) {
      if (x <= g[i][0] && g[i].back() <= y) {
        tot += co * sum[i] + co_sum[i];
        all_sum += sum[i];
        co += 2 * ((int)(g[i]).size());
        cnt += ((int)(g[i]).size());
      } else if ((x <= g[i][0] && g[i][0] <= y) ||
                 (x <= g[i].back() && g[i].back() <= y) ||
                 (g[i][0] <= x && y <= g[i].back())) {
        for (int j = (0); j < int(((int)(g[i]).size())); ++j)
          if (x <= g[i][j] && g[i][j] <= y) {
            tot += co * g[i][j];
            all_sum += g[i][j];
            co += 2;
            cnt++;
          }
      }
    }
  return tot - (cnt - 1) * all_sum;
}
int main() {
  cin >> n;
  for (int i = (0); i < int(n); ++i) cin >> arr[i], g[0].push_back(arr[i]);
  sort((g[0]).begin(), (g[0]).end());
  int q;
  cin >> q;
  while (q--) {
    int tp, x, y;
    cin >> tp >> x >> y;
    if (tp == 1) {
      x--;
      del(arr[x]);
      arr[x] += y;
      add(arr[x]);
    } else if (tp == 2) {
      cout << query(x, y) << endl;
    }
  }
  return 0;
}
