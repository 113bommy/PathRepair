#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<long long> v(n), a(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  priority_queue<pair<int, int> > pq;
  int i = 0;
  for (; i < k; i++) pq.push(make_pair(v[i], i));
  for (; i < n; i++) {
    pq.push(make_pair(v[i], i));
    a[pq.top().second] = i;
    pq.pop();
  }
  for (; !pq.empty(); i++) {
    a[pq.top().second] = i;
    pq.pop();
  }
  long long sum = 0;
  for (i = 0; i < n; i++) sum += (a[i] - i) * v[i];
  cout << sum << "\n";
  for (i = 0; i < n; i++) {
    if (i + 1 == n)
      cout << a[i] + 1 << "\n";
    else
      cout << a[i] + 1 << " ";
  }
}
