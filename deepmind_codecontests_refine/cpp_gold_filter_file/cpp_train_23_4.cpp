#include <bits/stdc++.h>
using namespace std;
long long n;
long long k;
struct book {
  bool a;
  bool b;
  int time;
};
book B[1000000];
bool compare(book x, book y) { return x.time < y.time; }
void solve() {
  cin >> n;
  cin >> k;
  int x, y, z;
  int as = 0;
  int bs = 0;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z;
    B[i].a = y;
    as += y;
    bs += z;
    B[i].b = z;
    B[i].time = x;
    mx = max(mx, B[i].time);
  }
  if (as < k || bs < k) {
    cout << -1 << endl;
    return;
  }
  sort(B, B + n, compare);
  long long tot = 0;
  int ak = 0;
  int bk = 0;
  stack<int> a;
  stack<int> b;
  for (int i = 0; i < n; i++) {
    if (B[i].a && B[i].b) continue;
    if (ak < k && B[i].a) {
      ak++;
      a.push(i);
      tot += B[i].time;
    }
    if (bk < k && B[i].b) {
      bk++;
      tot += B[i].time;
      b.push(i);
    }
  }
  int lst = 0;
  int used[1000000] = {0};
  for (int i = 0; i < n; i++) {
    if (ak < k && B[i].a && B[i].b) {
      ak++;
      tot += B[i].time;
      if (b.size() && bk == k) {
        tot -= B[b.top()].time;
        b.pop();
      }
      if (bk < k) bk++;
      lst = i;
      used[i] = 1;
    } else if (bk < k && B[i].a && B[i].b) {
      bk++;
      tot += B[i].time;
      if (a.size() && ak == k) {
        tot -= B[a.top()].time;
        a.pop();
      }
      lst = i;
      used[i] = 1;
      if (ak < k) ak++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a.size() == 0 || b.size() == 0) break;
    if (used[i]) continue;
    int m = a.top();
    int n = b.top();
    if (B[i].a && B[i].b) {
      if (B[i].time < B[m].time + B[n].time) {
        tot = tot - (B[m].time + B[n].time);
        tot += B[i].time;
        a.pop();
        b.pop();
      }
    }
  }
  cout << tot << endl;
  return;
}
int main() {
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
