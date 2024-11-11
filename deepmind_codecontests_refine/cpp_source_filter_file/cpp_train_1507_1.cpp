#include <bits/stdc++.h>
using namespace std;
const int MAXI = numeric_limits<int>::max() / 2;
const int MINI = numeric_limits<int>::min() / 2;
const long long MAXL = numeric_limits<long long>::max() / 2;
const long long MINL = numeric_limits<long long>::min() / 2;
static const int N = 300000;
int a[N], pre[N], dp[N];
int main(int argc, char* argv[]) {
  int i, n, s, l;
  cin >> n >> s >> l;
  deque<int> q1, q2;
  int tmp = -1;
  for ((i) = (0); (i) < (n); ++(i)) {
    cin >> a[i];
    while (!q1.empty() && a[q1.back()] >= a[i]) q1.pop_back();
    while (!q2.empty() && a[q2.back()] <= a[i]) q2.pop_back();
    q1.push_back(i);
    q2.push_back(i);
    while (!q1.empty() && !q2.empty() && a[q2.front()] - a[q1.front()] > s) {
      if (q1.front() < q2.front()) {
        tmp = q1.front();
        q1.pop_front();
      } else {
        tmp = q2.front();
        q2.pop_front();
      }
    }
    if (q1.empty() || q2.empty())
      pre[i] = 1;
    else
      pre[i] = i - tmp;
  }
  int ans = 1;
  deque<int> que;
  memset(dp, 0, sizeof(dp));
  ;
  for ((i) = (0); (i) < (n); ++(i)) {
    if (pre[i] < l)
      dp[i] = MAXI;
    else if (i - pre[i] <= 0)
      dp[i] = 1;
    else {
      while (!que.empty() && que.front() < i - pre[i]) que.pop_front();
      if (que.empty())
        dp[i] = 1;
      else if (dp[que.front()] == MAXI)
        dp[i] = MAXI;
      else
        dp[i] = dp[que.front()] + 1;
    }
    if (i >= l - 1) {
      while (!que.empty() && dp[i - l + 1] <= dp[que.back()]) que.pop_back();
      que.push_back(i - l + 1);
    }
  }
  cout << (dp[n - 1] == MAXI ? -1 : dp[n - 1]) << endl;
  return 0;
}
