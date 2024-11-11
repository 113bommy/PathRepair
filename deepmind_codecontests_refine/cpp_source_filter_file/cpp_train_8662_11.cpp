#include <bits/stdc++.h>
using namespace std;
struct Decision {
  long long int start_idx, cost, reward;
};
bool operator<(const Decision& lhs, const Decision& rhs) {
  return make_pair(-lhs.cost, -lhs.reward) <= make_pair(-rhs.cost, -rhs.reward);
}
long long int n, vals[105], blk[2], blk01, num[2], cost;
priority_queue<Decision> pq[2], pq_other[2];
void proc(long long int x) {
  cost += blk[x];
  while (!pq[x].empty()) {
    if (num[x] >= pq[x].top().cost) {
      num[x] -= pq[x].top().cost;
      cost -= pq[x].top().reward;
      pq[x].pop();
    } else
      return;
  }
}
void processBlock(long long int start, long long int end, long long int sz,
                  long long int start_idx) {
  assert(sz > 0);
  Decision tmp;
  tmp.start_idx = start_idx;
  if (start == -1) {
    blk[end]++;
    tmp.cost = sz;
    tmp.reward = 1;
    pq_other[end].push(tmp);
  } else if (end == -1) {
    blk[start]++;
    tmp.cost = sz;
    tmp.reward = 1;
    pq_other[start].push(tmp);
  } else {
    if (start != end)
      blk01++;
    else {
      blk[start] += 2;
      tmp.cost = sz;
      tmp.reward = 2;
      pq[start].push(tmp);
    }
  }
}
void proc_other(long long int x) {
  while (!pq_other[x].empty()) {
    if (num[x] >= pq_other[x].top().cost) {
      num[x] -= pq_other[x].top().cost;
      cost -= pq_other[x].top().reward;
      pq[x].pop();
    } else
      return;
  }
}
long long int compute_cost() {
  long long int ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    if (vals[i] % 2 != vals[i + 1] % 2) ans++;
  }
  return ans;
}
int main() {
  cin >> n;
  bool inBlock = false;
  long long int sz = 0, start = 0;
  cost = 0;
  vals[0] = -1;
  num[0] = n / 2;
  num[1] = n - num[0];
  blk[0] = 0;
  blk[1] = 0;
  blk01 = 0;
  for (int i = 1; i <= n; i++) {
    cin >> vals[i];
    if (vals[i] == 0) {
      if (inBlock) {
        sz++;
      } else {
        inBlock = true;
        sz = 1;
        start = vals[i - 1] % 2;
      }
    } else {
      num[vals[i] % 2]--;
      if (inBlock) {
        inBlock = false;
        long long int end = vals[i] % 2;
        processBlock(start, end, sz, i - sz);
      } else {
        assert(vals[i - 1] != 0);
        if (i != 1 && vals[i - 1] % 2 != vals[i] % 2) {
          cost++;
        }
      }
    }
  }
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  if (inBlock) {
    if (start == -1) {
      cout << 1 << endl;
      return 0;
    } else {
      processBlock(start, -1, sz, n + 1 - sz);
    }
  }
  cost += blk01;
  proc(0);
  proc(1);
  proc_other(0);
  proc_other(1);
  cout << cost << endl;
}
