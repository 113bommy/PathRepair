#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int n, h, k;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (cin >> n; n; --n) {
    cin >> k;
    pq.push(k);
    if (pq.top() < k) {
      h += k - pq.top();
      pq.pop();
      pq.push(k);
    }
  }
  cout << h << '\n';
  return 0;
}
