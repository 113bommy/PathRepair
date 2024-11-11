#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int n;
  cin >> n;
  deque<int> q;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    q.push_back(x);
  }
  int i = 0;
  int s = 0, d = 0;
  while (!q.empty()) {
    if (i % 2 == 0) {
      if (q.front() > q.back()) {
        s += q.front();
        q.pop_front();
      } else {
        s += q.back();
        q.pop_back();
      }
    } else {
      if (q.front() > q.back()) {
        d += q.front();
        q.pop_front();
      } else {
        d += q.back();
        q.pop_back();
      }
    }
  }
  cout << s << " " << d;
  return 0;
}
