#include <bits/stdc++.h>
const int MAX_N = (int)6e5 + 123;
const double eps = 1e-6;
const int inf = (int)1e9 + 123;
using namespace std;
int n;
int whom[MAX_N];
vector<int> second;
int lll[20], rrr[20];
int sa[MAX_N], pos[MAX_N], for_time[MAX_N], len;
int lcp[MAX_N];
bool cmp(int x, int y) {
  if (len == 1) return pos[x] < pos[y];
  if (pos[x] != pos[y]) return pos[x] < pos[y];
  x = (x + len / 2) % int((second).size()),
  y = (y + len / 2) % int((second).size());
  return pos[x] < pos[y];
}
void outt(int x) {
  if (x < 0)
    cout << '#';
  else
    cout << char(x + 'a');
}
void out() {
  for (auto i : second) outt(i);
  cout << endl;
  for (int i = 0; i < int((second).size()); i++) {
    cout << i << " ->";
    for (int j = sa[i]; j < int((second).size()); j++) outt(second[j]);
    cout << ' ' << whom[sa[i]];
    cout << endl;
  }
}
void build_sa() {
  for (int i = 0; i < int((second).size()); i++) {
    pos[i] = second[i];
    sa[i] = i;
  }
  for (int h = 0;; h++) {
    len = (1 << h);
    sort(sa, sa + int((second).size()), &cmp);
    int color = 0;
    for (int i = 0; i < int((second).size()); i++) {
      if (i > 0 && cmp(sa[i - 1], sa[i])) color++;
      for_time[sa[i]] = color;
    }
    for (int i = 0; i < int((second).size()); i++) pos[i] = for_time[i];
    if (color == int((second).size()) - 1) break;
  }
  for (int i = 0, len = 0; i < int((second).size()); i++) {
    len = max(len - 1, 0);
    if (pos[i] == int((second).size()) - 1) {
      lcp[pos[i]] = len = 0;
      continue;
    }
    int j = sa[pos[i] + 1];
    while (second[(i + len) % int((second).size())] ==
           second[(j + len) % int((second).size())])
      len++;
    lcp[pos[i]] = len;
  }
}
int cnt[15][MAX_N];
int dp[20][MAX_N], lg[MAX_N];
void build_sparse() {
  for (int i = 0; i < int((second).size()); i++) {
    if (i > 0)
      for (int j = 1; j <= n; j++) cnt[j][i] = cnt[j][i - 1];
    if (whom[sa[i]] > 0) cnt[whom[sa[i]]][i]++;
  }
  for (int i = 0; i < int((second).size()); i++) dp[0][i] = lcp[i];
  for (int it = 1; it < 20; it++)
    for (int i = 0; i + (1 << it) - 1 < int((second).size()); i++)
      dp[it][i] = min(dp[it - 1][i], dp[it - 1][i + (1 << (it - 1))]);
  for (int i = 1, j = 0; i <= int((second).size()); i++) {
    if ((1 << (j + 1)) == i) j++;
    lg[i] = j;
  }
}
int get_min(int l, int r) {
  int len = r - l + 1;
  return min(dp[lg[len]][l], dp[lg[len]][r - (1 << lg[len]) + 1]);
}
int getL(int x, int len) {
  int l = 0, r = x - 1, ans = x, mid = -1;
  while (l <= r) {
    mid = (l + r) / 2;
    if (get_min(mid, x - 1) >= len) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ans;
}
int getR(int x, int len) {
  int l = x + 1, r = int((second).size()) - 1, ans = x, mid = -1;
  while (l <= r) {
    mid = (l + r) / 2;
    if (get_min(x, mid - 1) >= len) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return ans;
}
int how_many(int L, int R, int tp) {
  int res = cnt[tp][R];
  if (L > 0) res -= cnt[tp][L - 1];
  return res;
}
int FindL(int id, int L, int R, int tp) {
  int l = L, r = R, mid = -1, ans = -1, now;
  while (l <= r) {
    mid = (l + r) / 2;
    now = how_many(getL(id, mid), getR(id, mid), tp);
    if (lll[tp] <= now) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return ans;
}
int FindR(int id, int L, int R, int tp) {
  int l = L, r = R, mid = -1, ans = -1, now;
  while (l <= r) {
    mid = (l + r) / 2;
    now = how_many(getL(id, mid), getR(id, mid), tp);
    if (now <= rrr[tp]) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ans;
}
int tt;
int ccount(int id, int L, int R) {
  pair<int, int> now = make_pair(L, R);
  for (int i = 1; i <= n; i++) {
    int l = FindL(id, L, R, i), r = FindR(id, L, R, i);
    swap(l, r);
    if (l == -1 || r == -1 || l > r) return 0;
    if (now.first == -1)
      now = make_pair(l, r);
    else {
      if (now.second < l || r < now.first) return 0;
      now.first = max(now.first, l);
      now.second = min(now.second, r);
    }
  }
  return now.second - now.first + 1;
}
long long get() {
  long long res = 0;
  for (int i = 0, last = -1; i < int((second).size()); i++) {
    if (whom[sa[i]] != 0) continue;
    int len = 0;
    if (last >= 0) {
      len = get_min(last, i - 1);
    }
    if (len + 1 <= tt - sa[i]) res += ccount(i, len + 1, tt - sa[i]);
    last = i;
  }
  return res;
}
int main() {
  ios_base ::sync_with_stdio(NULL), cin.tie(NULL);
  string nw;
  cin >> nw;
  tt = int((nw).size());
  for (int j = int((second).size());
       j <= int((second).size()) + int((nw).size()) - 1; j++)
    whom[j] = 0;
  whom[int((second).size()) + int((nw).size())] = -1;
  for (auto i : nw) second.push_back(i - 'a');
  int hey = 0;
  second.push_back(--hey);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> nw >> lll[i] >> rrr[i];
    for (int j = int((second).size());
         j <= int((second).size()) + int((nw).size()) - 1; j++)
      whom[j] = i;
    whom[int((second).size()) + int((nw).size())] = -1;
    for (auto i : nw) second.push_back(i - 'a');
    second.push_back(--hey);
  }
  build_sa();
  build_sparse();
  cout << get();
  return 0;
}
