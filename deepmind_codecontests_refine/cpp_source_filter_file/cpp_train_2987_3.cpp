#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int n) {
  long long int p = 1;
  while (n > 0) {
    if (n & 1) {
      p = ((p % 1000000007) * (a % 1000000007)) % 1000000007;
    }
    n >>= 1;
    a = ((a % 1000000007) * (a % 1000000007)) % 1000000007;
  }
  return p % 1000000007;
}
map<long long int, long long int> mp;
long long int ans[500005];
long long int BIT[500005];
void update(long long int idx, long long int val) {
  while (idx < 500005) {
    BIT[idx] = min(val, BIT[idx]);
    idx += idx & -idx;
  }
}
long long int query(long long int idx) {
  long long int sum = LLONG_MAX;
  while (idx > 0) {
    sum = min(sum, BIT[idx]);
    idx -= idx & -idx;
  }
  return sum;
}
int main() {
  long long int n;
  cin >> n;
  set<long long int> S;
  long long int arr[n];
  long long int co[n];
  for (long long int i = 0; i < 500005; i++) BIT[i] = LLONG_MAX;
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    S.insert(arr[i]);
  }
  long long int k = 1;
  for (auto i : S) mp[i] = k++;
  for (long long int i = 0; i < n; i++) {
    cin >> co[i];
    ans[i] = co[i];
  }
  for (long long int i = 0; i < n; i++) {
    long long int q = query(mp[arr[i]] - 1);
    if (q != LLONG_MAX)
      ans[i] += q;
    else
      ans[i] = -1;
    update(mp[arr[i]], co[i]);
  }
  for (long long int i = 0; i < 500005; i++) BIT[i] = LLONG_MAX;
  k += 2;
  for (auto i : S) mp[i] = k--;
  for (long long int i = 0; i < n; i++) {
    long long int q = query(mp[arr[n - 1 - i]] - 1);
    if (q != LLONG_MAX && ans[i] != -1)
      ans[n - 1 - i] += q;
    else
      ans[n - 1 - i] = -1;
    update(mp[arr[n - 1 - i]], co[n - 1 - i]);
  }
  long long int answer = LLONG_MAX;
  for (long long int i = 0; i < n; i++) {
    if (ans[i] != -1) answer = min(answer, ans[i]);
  }
  if (answer == LLONG_MAX) answer = -1;
  cout << answer << endl;
}
