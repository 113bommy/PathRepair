#include <bits/stdc++.h>
using namespace std;
long long int n;
vector<long long int> res(200005);
pair<long long int, long long int> inp(long long int l, long long int r) {
  pair<long long int, long long int> a;
  cout << "? " << l << " " << r << "\n";
  fflush(stdout);
  cin >> a.first >> a.second;
  return a;
}
void func(long long int l, long long int r) {
  if (l > r) return;
  pair<long long int, long long int> a = inp(l, r);
  if ((r - l + 1) / 2 <= a.second) {
    long long int l0 = r - a.second + 1, r0 = l + a.second - 1;
    for (long long int i = l0; i <= r0; i++) res[i] = a.first;
    func(l, l0 - 1);
    func(r0 + 1, r);
  } else {
    long long int m = (l + r) / 2;
    func(l, m);
    func(m + 1, r);
  }
}
void solve() {
  cin >> n;
  func(1, n);
  cout << "! ";
  for (long long int i = 1; i <= n; i++) cout << res[i] << " ";
}
int main() {
  long long int qc = 1;
  for (long long int i = 1; i <= qc; i++) solve();
}
