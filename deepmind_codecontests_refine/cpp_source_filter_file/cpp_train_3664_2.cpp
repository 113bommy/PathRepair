#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int n, p;
long long int curent, ans[N];
priority_queue<pair<int, int> > q1;
queue<int> q;
priority_queue<int> q2;
int main() {
  cin >> n >> p;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    q1.push(make_pair(-x, -i));
  }
  for (int i = 1; i <= n; ++i) {
    if (q.empty()) {
      curent = -q1.top().first;
    }
    curent += p;
    while (q1.size() && -q1.top().first <= curent) {
      if (q.empty() || q.back() > -q1.top().second) {
        q.push(-q1.top().second);
      } else {
        q2.push(q1.top().second);
      }
      q1.pop();
    }
    ans[q.front()] = curent;
    q.pop();
    if (q2.size() && q.empty()) {
      q.push(-q2.top()), q2.pop();
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i];
  }
  return 0;
}
