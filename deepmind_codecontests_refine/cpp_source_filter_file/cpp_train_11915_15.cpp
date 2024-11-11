#include <bits/stdc++.h>
using namespace std;
long long int row[1010];
long long int col[1010];
long long int ans[1000010];
long long int ans2[1000010];
priority_queue<long long int> pq1, pq2;
int main() {
  int test;
  long long int n, m, k, p, tt;
  cin >> n >> m >> k >> p;
  long long int rr = 0, cc = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> tt;
      row[i] += tt;
      col[j] += tt;
    }
  }
  for (int i = 0; i < n; i++) pq1.push(row[i]);
  for (int i = 0; i < m; i++) pq2.push(col[i]);
  for (int i = 1; i <= k; i++) {
    rr = pq1.top();
    pq1.pop();
    cc = pq2.top();
    pq2.pop();
    ans[i] = ans[i - 1] + rr;
    ans2[i] = ans2[i - 1] + cc;
    rr -= (p * m);
    cc -= (p * n);
    pq1.push(rr);
    pq2.push(cc);
  }
  long long int gg = INT_MIN;
  for (long long int i = 0; i <= k; i++) {
    gg = max(gg, ans[i] + ans2[k - i] - (k - i) * i * p);
  }
  cout << gg << endl;
}
