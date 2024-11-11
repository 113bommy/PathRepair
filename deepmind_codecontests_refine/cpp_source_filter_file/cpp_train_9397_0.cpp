#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long int gcd(long long int A, long long int B) {
  if (!B) return A;
  return gcd(B, A % B);
}
const int MAXN = 1e5;
long long int lg[MAXN + 1];
long long int power[100];
vector<pair<long long int, long long int> > ans;
void solve(int l, int r) {
  if (l >= r) return;
  if (r == l - 1) {
    ans.push_back({l, r});
    return;
  }
  int mid = (l + r) / 2;
  solve(l, mid);
  solve(mid + 1, r);
  for (int i = l; i <= mid; i++) {
    ans.push_back({i, mid + i - l + 1});
  }
}
int main() {
  int n;
  cin >> n;
  if (n == 1)
    cout << 1;
  else {
    long long int r = 1;
    while (2 * r <= n) r *= 2;
    solve(1, r);
    if (r != n) solve(n - r + 1, n);
    cout << (int)(ans.size()) << '\n';
    for (auto x : ans) {
      cout << x.first << " " << x.second << '\n';
    }
  }
}
