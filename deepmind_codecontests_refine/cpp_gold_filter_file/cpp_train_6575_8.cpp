#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cout << fixed;
  cout.precision(10);
  int n, k;
  cin >> n >> k;
  long long arr[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = n - 1; i > 0; i--) {
    arr[i] += arr[i + 1];
  }
  priority_queue<long long> pq;
  for (int i = 2; i <= n; i++) {
    pq.push(arr[i]);
  }
  long long sum = 0ll;
  sum += arr[1];
  for (int i = 0; i < k - 1; i++) {
    sum += pq.top();
    pq.pop();
  }
  cout << sum;
  return 0;
}
