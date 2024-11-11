#include <bits/stdc++.h>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> pq1, pq2;
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    res *= a;
    b--;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, i, n, arr[300005];
  stack<long long> sta;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (i = 1; i < n; i++) {
      if (sta.size() == 0) {
        sta.push(arr[i]);
      } else {
        while (sta.size() > 0 && arr[i] >= sta.top()) {
          sta.pop();
        }
        sta.push(arr[i]);
      }
    }
    long long a = sta.top();
    if (a >= arr[0])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    while (!sta.empty()) {
      sta.pop();
    }
  }
  return 0;
}
