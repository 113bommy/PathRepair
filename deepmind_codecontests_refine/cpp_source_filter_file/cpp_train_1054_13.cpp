#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
const long long int MAXINT = 1152921504606846976;
vector<pair<int, long long int>> neighbors[MAXN];
vector<pair<pair<int, int>, int>> queries[MAXN];
bitset<MAXN> visited;
struct node {
  long long int minimum, lazy;
} segment[MAXN * 4];
int timer, n;
long long int height[MAXN];
int finishing_time[MAXN], answer[MAXN];
void dfs_1(int v, long long int level) {
  visited[v] = true;
  height[v] = level;
  timer++;
  for (pair<int, long long int> i : neighbors[v])
    if (!visited[i.first]) dfs_1(i.first, level + i.second);
  finishing_time[v] = timer - 1;
  return;
}
void apply_lazy(int current) {
  segment[current * 2 + 1].minimum += segment[current].lazy;
  segment[current * 2 + 1].lazy += segment[current].lazy;
  segment[current * 2 + 2].minimum += segment[current].lazy;
  segment[current * 2 + 2].lazy += segment[current].lazy;
  segment[current].lazy = 0;
  return;
}
long long int get_answer(int from, int to, int current, int beginning,
                         int ending) {
  if (from > ending || to < beginning)
    return MAXINT;
  else if (beginning <= from && to <= ending)
    return segment[current].minimum;
  int mid = (from + to) / 2;
  apply_lazy(current);
  return min(get_answer(from, mid, current * 2 + 1, beginning, ending),
             get_answer(mid + 1, to, current * 2 + 2, beginning, ending));
}
void update(int from, int to, int current, int beginning, int ending,
            long long int value) {
  if (from > ending || to < beginning) {
    segment[current].minimum += value;
    segment[current].lazy += value;
    return;
  } else if (beginning <= from && to <= ending) {
    segment[current].minimum -= value;
    segment[current].lazy -= value;
    return;
  }
  apply_lazy(current);
  int mid = (from + to) / 2;
  update(from, mid, current * 2 + 1, beginning, ending, value);
  update(mid + 1, to, current * 2 + 2, beginning, ending, value);
  segment[current].minimum =
      min(segment[current * 2 + 1].minimum, segment[current * 2 + 2].minimum);
  return;
}
void construct(int from, int to, int current) {
  if (from == to) {
    segment[current].minimum =
        (neighbors[from].size() == 1 ? height[from] : MAXINT);
    return;
  }
  int mid = (from + to) / 2;
  construct(from, mid, current * 2 + 1);
  construct(mid + 1, to, current * 2 + 2);
  segment[current].minimum =
      min(segment[current * 2 + 1].minimum, segment[current * 2 + 2].minimum);
  return;
}
void dfs_2(int v) {
  visited[v] = true;
  for (pair<pair<int, int>, int> i : queries[v])
    answer[i.second] = get_answer(0, n - 1, 0, i.first.first, i.first.second);
  for (pair<int, long long int> i : neighbors[v])
    if (!visited[i.first]) {
      update(0, n - 1, 0, i.first, finishing_time[i.first], i.second);
      dfs_2(i.first);
      update(0, n - 1, 0, i.first, finishing_time[i.first], -i.second);
    }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, u, w, from, to;
  cin >> n >> t;
  for (int i = 1; i < n; i++) {
    cin >> u >> w;
    u--;
    neighbors[u].emplace_back(i, w);
    neighbors[i].emplace_back(u, w);
  }
  dfs_1(0, 0);
  construct(0, n - 1, 0);
  visited.reset();
  for (int q = 0; q < t; q++) {
    cin >> u >> from >> to;
    u--;
    from--;
    to--;
    queries[u].emplace_back(make_pair(from, to), q);
  }
  dfs_2(0);
  for (int q = 0; q < t; q++) cout << answer[q] << '\n';
  return 0;
}
