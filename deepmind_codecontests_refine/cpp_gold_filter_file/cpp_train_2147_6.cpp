#include <bits/stdc++.h>
using namespace std;
void Xarr() {
  long long k1, k2, k3;
  cin >> k1 >> k2 >> k3;
  long long t1, t2, t3;
  cin >> t1 >> t2 >> t3;
  long long n;
  cin >> n;
  k1 = min(k1, n);
  k2 = min(k2, n);
  k3 = min(k3, n);
  priority_queue<long long, vector<long long>, greater<long long>> pq1;
  for (long long i = 0; i < k1; i++) pq1.push(0);
  priority_queue<long long, vector<long long>, greater<long long>> pq2;
  for (long long i = 0; i < k2; i++) pq2.push(0);
  priority_queue<long long, vector<long long>, greater<long long>> pq3;
  for (long long i = 0; i < k3; i++) pq3.push(0);
  long long ans = INT_MIN;
  for (long long i = 0; i < n; i++) {
    long long cr;
    cin >> cr;
    long long smallans = 0;
    long long p1 = pq1.top();
    pq1.pop();
    if (p1 > cr)
      smallans += p1 - cr;
    else
      p1 = cr;
    cr = t1 + p1;
    p1 = cr;
    pq1.push(p1);
    long long p2 = pq2.top();
    pq2.pop();
    if (p2 > cr)
      smallans += p2 - cr;
    else
      p2 = cr;
    cr = t2 + p2;
    p2 = cr;
    pq2.push(p2);
    long long p3 = pq3.top();
    pq3.pop();
    if (p3 > cr)
      smallans += p3 - cr;
    else
      p3 = cr;
    cr = t3 + p3;
    p3 = cr;
    pq3.push(p3);
    ans = max(smallans, ans);
  }
  cout << ans + t1 + t2 + t3 << "\n";
}
int32_t main() {
  cout << fixed << setprecision(16);
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Xarr();
}
