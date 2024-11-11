#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
const long long mod = 1000000000 + 7;
int n;
long long ans[maxn], p;
struct node {
  long long x, f, id;
  bool operator<(const node &a) const {
    if (x == a.x) {
      if (f == a.f) return id > a.id;
      return f > a.f;
    }
    return x > a.x;
  }
} a[maxn];
priority_queue<node> q1;
priority_queue<long long, vector<long long>, greater<long long> > q2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> p;
  long long cnt = 0, count = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x;
    a[i].id = i;
    a[i].f = 0;
    q1.push(a[i]);
  }
  long long tmp = n + 1;
  while (!q1.empty()) {
    node now = q1.top();
    q1.pop();
    cnt = max(cnt, now.x);
    if (now.f == 0) {
      now.f = 1;
      if (now.id < tmp) {
        tmp = now.id, count++;
        now.x = cnt + p;
        cnt = max(cnt, now.x);
        q1.push(now);
      } else {
        q2.push(now.id);
      }
    } else {
      ans[now.id] = now.x;
      count--;
      if (count == 0) {
        if (!q2.empty()) {
          count++;
          q1.push({cnt += p, 1, q2.top()});
          tmp = q2.top();
          q2.pop();
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
