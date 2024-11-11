#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
vector<int> A, B, C;
int p[MAXN];
int cnt[MAXN];
long long A_sum[MAXN];
long long B_sum[MAXN];
int mapper[MAXN];
struct Node {
  int amount;
  long long sum;
  Node() {
    amount = 0;
    sum = 0;
  }
};
struct SegmentTree {
  Node ST[4 * MAXN];
  Node merge(Node A, Node B) {
    Node ans = A;
    ans.amount += B.amount;
    ans.sum += B.sum;
    return ans;
  }
  Node query(int node, int lo, int hi, int extra) {
    if (ST[node].amount <= extra) {
      return ST[node];
    }
    if (lo == hi) {
      Node ans;
      ans.amount = extra;
      ans.sum = 1LL * mapper[lo] * extra;
      return ans;
    }
    int mid = (lo + hi) >> 1;
    int left = node << 1;
    Node l = query(left, lo, mid, extra);
    extra -= l.amount;
    Node r;
    if (extra) r = query(left + 1, mid + 1, hi, extra);
    return merge(l, r);
  }
  void update(int node, int lo, int hi, int i, int val) {
    if (lo > i || hi < i) return;
    if (lo == hi) {
      ST[node].amount += val;
      ST[node].sum += 1LL * val * mapper[lo];
      return;
    }
    int mid = (lo + hi) >> 1;
    int left = node << 1;
    update(left, lo, mid, i, val);
    update(left + 1, mid + 1, hi, i, val);
    ST[node] = merge(ST[left], ST[left + 1]);
  }
} ST;
map<int, int> pos;
vector<int> prices;
int idx = 0;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    prices.push_back(p[i]);
  }
  sort(prices.begin(), prices.end());
  int e;
  for (int i = 0; i < n; i = e) {
    e = i;
    while (e < n && prices[e] == prices[i]) {
      e++;
    }
    pos[prices[i]] = idx;
    mapper[idx] = prices[i];
    idx++;
  }
  int A_sz;
  cin >> A_sz;
  for (int i = 1; i <= A_sz; i++) {
    int x;
    cin >> x;
    cnt[x] += 1;
  }
  int B_sz;
  cin >> B_sz;
  for (int i = 1; i <= B_sz; i++) {
    int x;
    cin >> x;
    cnt[x] += 2;
  }
  for (int i = 1; i <= n; i++) {
    if (!cnt[i]) {
      int cur_id = pos[p[i]];
      ST.update(1, 0, idx - 1, cur_id, 1);
      continue;
    }
    if (cnt[i] == 1) A.push_back(p[i]);
    if (cnt[i] == 2) B.push_back(p[i]);
    if (cnt[i] == 3) C.push_back(p[i]);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  long long ans = -1;
  for (int i = 1; i <= A.size(); i++) {
    A_sum[i] = A[i - 1] + A_sum[i - 1];
  }
  for (int i = 1; i <= B.size(); i++) {
    B_sum[i] = B[i - 1] + B_sum[i - 1];
  }
  for (int i = 1; i <= C.size(); i++) {
    int cur_id = pos[C[i - 1]];
    ST.update(1, 0, idx - 1, cur_id, 1);
  }
  int tot = k + k;
  if (tot == m) {
    if (A.size() >= k && B.size() >= k) ans = A_sum[k] + B_sum[k];
  }
  long long cur = 0;
  int pointer = A.size();
  int pointer2 = B.size();
  for (int i = 1; i <= C.size(); i++) {
    int cur_id = pos[C[i - 1]];
    ST.update(1, 0, idx - 1, cur_id, -1);
    cur += C[i - 1];
    int left = k - i;
    int will_use = i + left + left;
    if (will_use > m) continue;
    if (A.size() >= left && B.size() >= left) {
      while (pointer >= 1 && pointer > left) {
        cur_id = pos[A[pointer - 1]];
        ST.update(1, 0, idx - 1, cur_id, 1);
        pointer--;
      }
      while (pointer2 >= 1 && pointer2 > left) {
        cur_id = pos[B[pointer2 - 1]];
        ST.update(1, 0, idx - 1, cur_id, 1);
        pointer2--;
      }
      long long act = A_sum[left];
      act += B_sum[left];
      int missing = m - i - left - left;
      Node q = ST.query(1, 0, idx - 1, missing);
      if (q.amount != missing) continue;
      long long extra = q.sum;
      if (ans == -1)
        ans = cur + act + extra;
      else
        ans = min(ans, cur + act + extra);
    }
  }
  cout << ans << endl;
}
