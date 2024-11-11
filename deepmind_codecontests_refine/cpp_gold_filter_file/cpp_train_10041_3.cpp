#include <bits/stdc++.h>
using namespace std;
struct vote {
  int cost, key, idx;
  vote() {}
  vote(int cost, int key, int idx) : cost(cost), key(key), idx(idx) {}
  bool operator<(const vote& v) const {
    if (cost == v.cost) {
      if (key == v.key) return idx < v.idx;
      return key < v.key;
    }
    return cost < v.cost;
  }
};
const int INFTY = 1 << 30;
const int MAXN = 100005;
int N;
vector<int> cand[MAXN];
vote V[MAXN];
int BIT[MAXN][2];
void add(int idx, int val, int type) {
  for (; idx < MAXN; idx += idx & -idx) BIT[idx][type] += val;
}
int get(int idx, int type) {
  int ret = 0;
  for (; idx > 0; idx -= idx & -idx) ret += BIT[idx][type];
  return ret;
}
int binary_search(int need) {
  int lo = 0, hi = N;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    int ret = get(mid, 1);
    if (ret == need)
      return mid;
    else if (ret < need)
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  return lo;
}
bool compare_key(vote v1, vote v2) {
  if (v1.key == v2.key) return v1.cost < v2.cost;
  return v1.key < v2.key;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    cand[a].push_back(b);
  }
  for (int i = 1; i < MAXN; i++) sort(cand[i].rbegin(), cand[i].rend());
  int index = 0;
  for (int i = 0; i < MAXN; i++)
    for (int j = 0; j < cand[i].size(); j++) {
      V[index] = vote(cand[i][j], j + 1, index);
      index++;
    }
  sort(V, V + N);
  for (int i = 0; i < N; i++) {
    V[i].idx = i + 1;
    add(i + 1, V[i].cost, 0);
    add(i + 1, 1, 1);
  }
  sort(V, V + N, compare_key);
  int best = INFTY, cur = 0, cnt = 0, left = N - 1;
  for (int i = N; i >= 1; i--) {
    while (left >= 0 && V[left].key >= i) {
      cur += V[left].cost;
      cnt++;
      add(V[left].idx, -V[left].cost, 0);
      add(V[left].idx, -1, 1);
      left--;
    }
    int need = max(0, i - cnt);
    int bitidx = binary_search(need);
    int ncost = get(bitidx, 0);
    best = min(best, cur + ncost);
  }
  cout << best << "\n";
  return 0;
}
