#include <bits/stdc++.h>
using namespace std;
struct node {
  long long m, p;
  friend bool operator<(node a, node b) { return a.p < b.p; }
};
bool cmp(node a, node b) { return a.m < b.m; }
int main() {
  ios::sync_with_stdio(false);
  long long T;
  cin >> T;
  for (long long w = 0; w < T; w++) {
    long long n;
    cin >> n;
    node per[n];
    for (long long i = 0; i < n; i++) {
      cin >> per[i].m >> per[i].p;
    }
    sort(per, per + n, cmp);
    priority_queue<node> q;
    long long t = 0;
    for (long long i = 0; i < n; i++) {
      while (1) {
        if (per[t].m == i) {
          q.push(per[t]);
          t++;
        } else {
          break;
        }
      }
      if (q.empty()) {
        continue;
      } else {
        q.pop();
      }
    }
    long long ans = 0;
    while (!q.empty()) {
      node xx = q.top();
      q.pop();
      ans += xx.p;
    }
    cout << ans << endl;
  }
  return 0;
}
