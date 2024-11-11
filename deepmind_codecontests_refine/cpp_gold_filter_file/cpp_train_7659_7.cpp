#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-5;
int A[100001];
long long DP[100001];
int DP_rest[100001];
vector<vector<int> > TREE(100001);
long long find_max_b(int p, int s) {
  vector<long long> tmpA;
  int ts = TREE[s].size();
  if (DP[s] != -1) return DP[s];
  int child = 0;
  int parent_flag = 0;
  for (int i = 0; i < (int)(ts); i++) {
    if (TREE[s][i] != p)
      child++;
    else
      parent_flag = 1;
  }
  if (child == 0 || A[s] == parent_flag) {
    DP_rest[s] = A[s] - 1;
    return DP[s] = 1;
  }
  long long ret = parent_flag;
  int nums = A[s] - parent_flag;
  for (int i = 0; i < (int)(ts); i++) {
    if (p == TREE[s][i]) {
      tmpA.push_back(0);
      continue;
    }
    long long tmp_ret;
    tmp_ret = find_max_b(s, TREE[s][i]) + 1;
    tmpA.push_back(tmp_ret);
  }
  sort(tmpA.begin(), tmpA.end());
  int d = min(nums, ts - parent_flag);
  for (int i = 0; i < (int)(d); i++) {
    ret += tmpA[ts - 1 - i];
    nums--;
  }
  if (nums > 0) {
    int tmp_sum = 0;
    for (int i = 0; i < (int)(ts); i++) {
      if (TREE[s][i] == p) continue;
      tmp_sum += DP_rest[TREE[s][i]];
    }
    ret += min(nums, tmp_sum) * 2;
    nums -= min(nums, tmp_sum);
  }
  DP_rest[s] = nums;
  return DP[s] = ret;
}
int main(void) {
  int n, s;
  int nums;
  memset(A, 0, sizeof(A));
  memset(DP, -1, sizeof(DP));
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < (int)(n - 1); i++) {
    int a, b;
    cin >> a >> b;
    TREE[a].push_back(b);
    TREE[b].push_back(a);
  }
  cin >> s;
  nums = A[s];
  long long ret = 0;
  if (n != 1) ret = find_max_b(n + 1, s);
  cout << ret << endl;
  return 0;
}
