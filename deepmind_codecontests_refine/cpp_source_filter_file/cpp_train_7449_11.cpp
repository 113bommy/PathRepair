#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
int main() {
  cin.sync_with_stdio(false);
  int n, k, x;
  cin >> n >> k >> x;
  vector<int64_t> v(n, 0);
  int negcnt = 0;
  pair<int, int> maxneg = {-INF, -1};
  pair<int, int> minpos = {INF, -1};
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] < 0) {
      negcnt++;
      if (v[i] > maxneg.first) {
        maxneg = {v[i], i};
      }
    } else if (v[i] > 0) {
      if (v[i] < minpos.first) {
        minpos = {v[i], i};
      }
    }
  }
  if (negcnt % 2 == 0) {
    if (abs(maxneg.first) < abs(minpos.first)) {
      while (v[maxneg.second] <= 0 && k) {
        v[maxneg.second] += x;
        k--;
      }
    } else {
      while (v[minpos.second] >= 0 && k) {
        v[minpos.second] -= x;
        k--;
      }
    }
  }
  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>,
                 greater<pair<int64_t, int>>>
      q;
  for (int i = 0; i < n; i++) {
    q.push({abs(v[i]), i});
  }
  while (k) {
    pair<int, int> mlc = q.top();
    int pos = mlc.second;
    q.pop();
    if (v[pos] < 0) {
      v[pos] -= x;
    } else {
      v[pos] += x;
    }
    k--;
    q.push({abs(v[pos]), pos});
  }
  for (int i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  return 0;
}
