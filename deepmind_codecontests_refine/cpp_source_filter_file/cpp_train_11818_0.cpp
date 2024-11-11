#include <bits/stdc++.h>
using namespace std;
struct node {
  int pos;
  int pow;
};
int dp[1000001];
int compare(struct node a, struct node b) { return a.pos < b.pos; }
int binary_search(struct node arr[], int n, int val) {
  int start = 0;
  int end = n - 1;
  int mid;
  while (start <= end) {
    mid = (start + end) / 2;
    if (arr[mid].pos == val) {
      return mid;
    }
    if (arr[mid].pos < val)
      start = mid + 1;
    else
      end = mid - 1;
  }
  return -1;
}
int main() {
  int n;
  scanf("%d", &n);
  int i;
  struct node arr[n];
  for (i = 0; i <= n - 1; i++) {
    cin >> arr[i].pos >> arr[i].pow;
  }
  sort(arr, arr + n, compare);
  if (arr[0].pos == 0)
    dp[0] = 1;
  else
    dp[0] = 0;
  int mx = 0;
  int last = arr[n - 1].pos;
  for (i = 1; i <= last; i++) {
    int index = binary_search(arr, n, i);
    if (index != -1) {
      if (i - arr[index].pow - 1 > 0)
        dp[i] = 1 + dp[i - arr[index].pow - 1];
      else
        dp[i] = 1;
    } else
      dp[i] = dp[i - 1];
    mx = max(mx, dp[i]);
  }
  cout << n - mx << endl;
  return 0;
}
