#include <bits/stdc++.h>
using namespace std;
int n, vi[100002], fl;
set<int, greater<int> > pq[100002];
int fn2(int p) {
  if (p > n) return p - n;
  return p;
}
void fn(int p) {
  int i, fl2 = 1;
  for (i = p * p; i <= (n); i += p * 2) vi[i]++;
  p = n / p;
  for (i = 1; i <= n; i++) {
    if (pq[i] != pq[fn2(i + p)]) {
      fl2 = 0;
      break;
    }
  }
  if (fl2) fl = 1;
}
int main() {
  int m, a, b, i;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    if (a > b) swap(a, b);
    pq[a].insert(b - a);
    pq[b].insert(n - b + a);
  }
  if (n % 2 == 0) {
    fn(2);
  }
  if (fl) {
    cout << "Yes";
    return 0;
  }
  for (i = 3; i <= (n); i += 2) {
    if (vi[i]) continue;
    if (n % i == 0) {
      fn(i);
    }
    if (fl) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
