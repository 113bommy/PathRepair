#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  scanf("%Ld", &n);
  vector<long long> val(n);
  for (auto& i : val) {
    cin >> i;
  }
  vector<long long> pre_sum(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    if (val[i] < 0) {
      pre_sum[i + 1] = pre_sum[i];
    } else {
      pre_sum[i + 1] = pre_sum[i] + val[i];
    }
  }
  map<long long, int> last, first;
  for (int i = 0; i < n; ++i) {
    last[val[i]] = i;
    first[val[n - 1 - i]] = n - 1 - i;
  }
  long long ans = -100000000000000;
  long long opt_val;
  for (int i = 0; i < n; ++i) {
    if (last[val[i]] == first[val[i]]) continue;
    long long cur_ans =
        2 * val[i] + pre_sum[last[val[i]]] - pre_sum[first[val[i]] + 1];
    if (cur_ans > ans) {
      ans = cur_ans;
      opt_val = val[i];
    }
  }
  cout << ans << " ";
  int k = first[opt_val] + (n - 1 - last[opt_val]);
  for (int i = first[opt_val] + 1; i < last[opt_val]; ++i) {
    if (val[i] < 0) ++k;
  }
  printf("%d\n", k);
  for (int i = 0; i < first[opt_val]; ++i) {
    printf("%d ", i + 1);
  }
  for (int i = first[opt_val] + 1; i < last[opt_val]; ++i) {
    if (val[i] < 0) {
      printf("%d ", i + 1);
    }
  }
  for (int i = last[opt_val] + 1; i < n; ++i) {
    printf("%d", i + 1);
  }
}
