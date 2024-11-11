#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5, MAX_A = 1e5 + 5;
struct SegmentTree {
  int data[3 * MAX_N];
  SegmentTree() { memset(data, 0, sizeof(data)); }
  void build(int node, int le, int ri) {
    if (le == ri) {
      data[node] = 1;
      return;
    }
    int mid = (le + ri) / 2;
    build(2 * node, le, mid);
    build(2 * node + 1, mid + 1, ri);
    data[node] = data[2 * node] + data[2 * node + 1];
  }
  void mark_used(int node, int le, int ri, int ind) {
    if (le > ind || ri < ind) {
      return;
    } else if (le == ind && ri == ind) {
      data[node] = 0;
      return;
    }
    int mid = (le + ri) / 2;
    mark_used(2 * node, le, mid, ind);
    mark_used(2 * node + 1, mid + 1, ri, ind);
    data[node] = data[2 * node] + data[2 * node + 1];
  }
  int query(int node, int le, int ri, int q_le, int q_ri) {
    if (le > q_ri || ri < q_le) {
      return 0;
    } else if (le >= q_le && ri <= q_ri) {
      return data[node];
    }
    int mid = (le + ri) / 2;
    return query(2 * node, le, mid, q_le, q_ri) +
           query(2 * node + 1, mid + 1, ri, q_le, q_ri);
  }
} seg_tree;
vector<int> nums[MAX_A];
int cnt_between(int from, int to, int n) {
  if (to > from) {
    return seg_tree.query(1, 1, n, from + 1, to);
  } else {
    int ans = 0;
    ans += seg_tree.query(1, 1, n, from + 1, n);
    ans += seg_tree.query(1, 1, n, 1, to);
    return ans;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  set<int> all_nums;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    all_nums.insert(x);
    nums[x].push_back(i);
  }
  seg_tree.build(1, 1, n);
  int last = 0;
  long long ans = 0ll;
  for (int num : all_nums) {
    int le = 0, ri = nums[num].size() - 1, mid, st_ind = 0;
    while (le <= ri) {
      mid = (le + ri) / 2;
      if (nums[num][mid] > last) {
        st_ind = mid;
        ri = mid - 1;
      } else {
        le = mid + 1;
      }
    }
    int curr = st_ind;
    do {
      ans += 1ll * cnt_between(last, nums[num][curr], n);
      seg_tree.mark_used(1, 1, n, nums[num][curr]);
      last = nums[num][curr];
      curr++;
      if (curr == nums[num].size()) {
        curr = 0;
      }
    } while (curr != st_ind);
  }
  printf("%lld\n", ans);
  return 0;
}
