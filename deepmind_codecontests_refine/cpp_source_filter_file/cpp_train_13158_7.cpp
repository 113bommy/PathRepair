#include <bits/stdc++.h>
using namespace std;
int sub = 1e6 + 5;
int main() {
  int n, k, idx = 1;
  cin >> n >> k;
  vector<long long> cm(n + 1);
  priority_queue<pair<long long, int> > pq;
  for (int x = 1; x <= n; x++) cin >> cm[x];
  for (int x = 1; x <= n; x++) cm[x] += cm[x - 1];
  while (true) {
    if (idx + k - 1 > n) break;
    long long sum = cm[idx + k - 1] - cm[idx - 1];
    pq.push(make_pair(sum, sub - idx));
    idx++;
  }
  int a, b;
  idx = 1;
  long long amx = 0, bmx = 0, left, right;
  pair<int, int> w;
  while (pq.size() > 1) {
    w = pq.top();
    while (sub - w.second < idx + k && !pq.empty()) {
      pq.pop();
      w = pq.top();
    }
    left = cm[idx + k - 1] - cm[idx - 1];
    right = w.first;
    if (left + right > amx + bmx && sub - w.second >= idx + k) {
      amx = left;
      bmx = right;
      a = idx;
      b = sub - w.second;
    }
    idx++;
  }
  cout << a << " " << b << "\n";
  return 0;
}
