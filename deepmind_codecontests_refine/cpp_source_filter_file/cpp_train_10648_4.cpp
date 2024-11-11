#include <bits/stdc++.h>
#pragma warning(disable : 4996)
template <typename T>
T min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
T max(T x, T y) {
  return x > y ? x : y;
};
const long long INF = 20000000050000;
const long long mod = 1000000007;
const long long MAXN = 300005;
int N, a[MAXN], D, ANS;
std::vector<int> Q[MAXN];
int pre[MAXN], nxt[MAXN];
std::set<int> S, rS, S2, rS2;
std::queue<int> del;
std::pair<int, int> find(int pos) {
  int r = *S2.lower_bound(pos);
  int l = *rS2.lower_bound(-pos);
  if (r <= N) del.push(r), S2.erase(r);
  if (l < 0) del.push(l), rS2.erase(l);
  return {-l, r};
}
void reset() {
  if (S2.empty()) {
    S2 = S, rS2 = rS;
    return;
  }
  while (!del.empty()) {
    if (del.front() > 0)
      S2.insert(del.front());
    else
      rS2.insert(del.front());
    del.pop();
  }
}
int T[MAXN];
void add(int p, int x) {
  while (p <= N) T[p] += x, p += p & -p;
}
int query(int p) {
  int ret = 0;
  while (p) ret += T[p], p -= p & -p;
  return ret;
}
void solve(int val) {
  reset();
  for (int i = Q[val].size() - 1; i >= 0; i--) {
    add(Q[val][i], -1);
    std::pair<int, int> t = find(Q[val][i]);
    if (t.first > 0) Q[val].push_back(t.first);
    if (t.second <= N) Q[val].push_back(t.second);
  }
  Q[val].push_back(0), Q[val].push_back(N + 1);
  std::sort(Q[val].begin(), Q[val].end());
  std::unordered_map<int, int> MAP;
  for (int i = 1; i < Q[val].size() - 1; i++) {
    int sum = query(Q[val][i]);
    if (MAP[sum]) {
      int l = Q[val][MAP[sum] - 1] + 1, r = Q[val][i + 1] - 1;
      if (a[Q[val][MAP[sum]]] == D) l = max(l, pre[Q[val][MAP[sum]]] + 1);
      if (a[Q[val][i]] == D) r = min(r, nxt[Q[val][i]] - 1);
      ANS = max(ANS, r - l + 1);
    }
    sum = query(Q[val][i] - 1);
    if (!MAP[sum]) MAP[sum] = i;
  }
  for (int i = 0; i < Q[val].size(); i++)
    if (a[Q[val][i]] == val) add(Q[val][i], -1);
}
bool init() {
  static int tmp[MAXN];
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", a + i), tmp[a[i]]++;
  for (int i = 1; i <= N; i++)
    if (tmp[i] > tmp[D]) D = i;
  int t = 0;
  for (int i = 1; i <= N; i++)
    if (tmp[i] == tmp[D]) t++;
  if (t > 1) {
    ANS = N;
    return false;
  }
  Q[D].push_back(0);
  for (int i = 1; i <= N; i++) {
    Q[a[i]].push_back(i);
    if (a[i] == D) S.insert(i), rS.insert(-i), add(i, 1);
  }
  Q[D].push_back(N + 1);
  for (int i = 1; i < Q[D].size() - 1; i++)
    pre[Q[D][i]] = Q[D][i - 1], nxt[Q[D][i]] = Q[D][i + 1];
  S.insert(0);
  S.insert(N + 1);
  rS.insert(0);
  rS.insert(-N - 1);
  return true;
}
int main() {
  if (init())
    for (int i = 1; i <= N; i++)
      if (Q[i].size() && i != D) solve(i);
  printf("%d\n", ANS);
  return 0;
}
