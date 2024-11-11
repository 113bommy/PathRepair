#include <bits/stdc++.h>
using namespace std;
long long n;
vector<pair<long long, long long> > arr;
map<long long, long long> key;
set<long long> dad;
long long dp[212345];
long long bit[212345];
void update(long long index, long long val) {
  if (index <= 0) return;
  while (index < 212345) {
    bit[index] = max(bit[index], val);
    index += (index & (-index));
  }
}
long long query(long long index) {
  if (index <= 0) return 0;
  long long ans = bit[index];
  while (index > 0) {
    ans = max(ans, bit[index]);
    index -= (index & (-index));
  }
  return ans;
}
int main() {
  scanf("%I64d", &n);
  long long x, y, ans, tim = 0;
  for (int a = 0; a < n; a++) {
    scanf("%I64d%I64d", &x, &y);
    arr.push_back(make_pair(x, y));
    dad.insert(x + y);
    dad.insert(x - y);
  }
  sort(arr.begin(), arr.end());
  while (!dad.empty()) {
    key[*dad.begin()] = ++tim;
    dad.erase(dad.begin());
  }
  for (int a = 0; a < n; a++) {
    dp[a] = query(key[arr[a].first - arr[a].second]) + 1;
    update(key[arr[a].first + arr[a].second], dp[a]);
  }
  ans = dp[0];
  for (int a = 0; a < n; a++) {
    ans = max(ans, dp[a]);
  }
  printf("%I64d\n", ans);
  return 0;
}
