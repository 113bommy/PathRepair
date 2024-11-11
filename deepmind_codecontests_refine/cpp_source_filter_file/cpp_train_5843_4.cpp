#include <bits/stdc++.h>
using namespace std;
const long long INF64 = 1e18;
struct myQueue {
  stack<pair<long long, long long>> s1, s2;
  int size() { return s1.size() + s2.size(); }
  bool isEmpty() { return size() == 0; }
  long long getMax() {
    if (isEmpty()) {
      return -INF64;
    }
    if (!s1.empty() && !s2.empty()) {
      return max(s1.top().second, s2.top().second);
    }
    if (!s1.empty()) {
      return s1.top().second;
    }
    return s2.top().second;
  }
  void push(long long val) {
    if (s2.empty()) {
      s2.push(make_pair(val, val));
    } else {
      s2.push(make_pair(val, max(val, s2.top().second)));
    }
  }
  void pop() {
    if (s1.empty()) {
      while (!s2.empty()) {
        if (s1.empty()) {
          s1.push(make_pair(s2.top().first, s2.top().first));
        } else {
          s1.push(
              make_pair(s2.top().first, max(s2.top().first, s1.top().second)));
        }
        s2.pop();
      }
    }
    assert(!s1.empty());
    s1.pop();
  }
};
int n, k, first;
vector<int> a;
vector<myQueue> q;
vector<queue<int>> pos;
vector<vector<long long>> d;
int main() {
  cin >> n >> k >> first;
  a = vector<int>(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  q = vector<myQueue>(first + 1);
  pos = vector<queue<int>>(first + 1);
  d = vector<vector<long long>>(n + 1, vector<long long>(first + 1, -INF64));
  d[0][first] = 0;
  pos[first].push(-1);
  q[first].push(0ll);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= first; ++j) {
      while (!pos[j].empty() && pos[j].front() < i - k - 1) {
        q[j].pop();
        pos[j].pop();
      }
    }
    for (int j = 0; j < first; ++j) {
      if (!q[j + 1].isEmpty()) {
        d[i][j] = max(d[i][j], q[j + 1].getMax() + a[i - 1]);
        q[j].push(d[i][j]);
        pos[j].push(i - 1);
      }
    }
  }
  long long ans = -INF64;
  for (int i = n - k + 1; i <= n; ++i) {
    ans = max(ans, *max_element(d[i].begin(), d[i].end()));
  }
  if (ans == -INF64) ans = -1;
  cout << ans << endl;
  return 0;
}
