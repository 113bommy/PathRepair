#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i] / 10;
    pq.push(pair<int, int>(10 - (a[i] % 10), i));
  }
  while (!pq.empty()) {
    pair<int, int> t = pq.top();
    pq.pop();
    int val = t.first;
    int ind = t.second;
    sum -= a[ind] / 10;
    a[ind] += val;
    sum += a[ind] / 10;
    if (a[ind] <= 100 && k >= val) {
      k -= val;
      pq.push(pair<int, int>(10 - (a[ind] % 10), ind));
    } else {
      sum -= a[ind] / 10;
      a[ind] -= val;
      sum += a[ind] / 10;
    }
    if (k < 0) break;
  }
  cout << sum;
  return 0;
}
