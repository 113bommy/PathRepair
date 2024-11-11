#include <bits/stdc++.h>
using namespace std;
long long calculate(long long n, long long x) {
  if (n < x) return 1e18;
  return (n % x) * (n / x + 1) * (n / x + 1) + (x - n % x) * (n / x) * (n / x);
}
int main() {
  long long int n, k;
  cin >> n >> k;
  long long int arr[n];
  vector<long long> parts(n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    parts[i] = 1;
  }
  priority_queue<pair<long long, long long int>> q;
  for (int i = 0; i < n; i++) {
    q.push(make_pair(
        calculate(arr[i], parts[i]) - calculate(arr[i], parts[i] + 1), i));
  }
  for (int i = 0; i < k - n; i++) {
    auto x = q.top();
    q.pop();
    long long index = x.second;
    parts[index]++;
    q.push(make_pair(calculate(arr[index], parts[index]) -
                         calculate(arr[index], parts[index] + 1),
                     index));
  }
  for (int i = 0; i < n; i++) {
    ans += calculate(arr[i], parts[i]);
  }
  cout << ans << endl;
}
