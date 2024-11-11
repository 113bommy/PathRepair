#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b) {
  if (a > b)
    return a;
  else
    return b;
}
long long int min(long long int a, long long int b) {
  if (a < b)
    return a;
  else
    return b;
}
void solve() {
  long long int n, x, y;
  cin >> n;
  long long int a[101] = {0};
  pair<long long int, long long int> p;
  cin >> x >> y;
  p = make_pair(x, y);
  for (long long int i = 1; i < n; i++) {
    cin >> x >> y;
    for (long long int i = x; i < y; i++) a[i]++;
  }
  long long int c = 0;
  for (long long int i = p.first; i <= p.second; i++) {
    if (!a[i]) c++;
  }
  cout << c;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int t = 1;
  if (!t) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
