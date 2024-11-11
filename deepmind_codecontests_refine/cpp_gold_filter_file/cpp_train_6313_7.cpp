#include <bits/stdc++.h>
using namespace std;
long long int binary_search(long long int s, long long int start,
                            long long int end, long long int sum[],
                            long long int num) {
  if (sum[start] - sum[s] >= num)
    return start;
  else if (sum[end] - sum[s] < num)
    return 1e6;
  else if (sum[end] - sum[s] >= num && sum[end - 1] - sum[s] < num)
    return end;
  long long int mid = (start + end) / 2;
  if (sum[mid] - sum[s] >= num && sum[mid - 1] - sum[s] < num) return mid;
  if (sum[mid] - sum[s] >= num)
    binary_search(s, start, mid - 1, sum, num);
  else
    binary_search(s, mid + 1, end, sum, num);
}
int main() {
  cin.tie(0);
  cout.tie(0);
  long long int n, i, j, v[100002], t[100002],
      sum[100002] = {0}, pos[100002], val[100002] = {0}, cut[100002] = {0};
  cin >> n;
  for (i = 1; i <= n; i++) cin >> v[i];
  for (i = 1; i <= n; i++) {
    cin >> t[i];
    sum[i] = sum[i - 1] + t[i];
  }
  for (i = 1; i <= n; i++) {
    pos[i] = binary_search(i - 1, i, n, sum, v[i]);
    if (pos[i] != 1e6) {
      cut[pos[i]]++;
      val[pos[i]] += v[i] - (sum[pos[i] - 1] - sum[i - 1]);
    }
  }
  for (i = 1; i <= n; i++) {
    cut[i] += cut[i - 1];
    val[i] += (i - cut[i]) * t[i];
    cout << val[i] << " ";
  }
  cout << endl;
  return 0;
}
