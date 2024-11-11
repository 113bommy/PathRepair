#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long sum(vector<long long> &v, long long a) {
  long long b = 0;
  for (long long i = 0; i < n; i++) {
    if (v[i] < a) {
      b += v[i];
    } else {
      b += a;
    }
  }
  return b;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  vector<long long> v(n);
  long long add = 0;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    add += v[i];
  }
  if (add < k) {
    cout << -1 << endl;
    return 0;
  }
  if (add == k) {
    return 0;
  }
  long long l = 0;
  long long r = 1000000000;
  while (l < r) {
    long long mid = (l + r + 1) / 2;
    if (sum(v, mid) < k) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  long long a = l;
  queue<pair<long long, long long>> q;
  long long rest = k - sum(v, a);
  for (long long i = 0; i < n; i++) {
    if (v[i] - a <= 0) {
      v[i] = 0;
    } else {
      v[i] = v[i] - a;
      q.push(make_pair(v[i], i));
    }
  }
  for (long long i = 0; i < rest; i++) {
    auto b = q.front();
    q.pop();
    b.first--;
    if (b.first > 0) {
      q.push(b);
    }
  }
  while (!q.empty()) {
    auto b = q.front();
    q.pop();
    cout << b.second + 1 << ' ';
  }
  cout << endl;
}
