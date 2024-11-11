#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const long long mod = 1e9 + 7;
const unsigned long long INF = 1e18;
const int N = 5001;
int n, idx1, idx2, a;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (a == 1) idx1 = i;
    if (a == n) idx2 = i;
  }
  if (idx1 > idx2) swap(idx1, idx2);
  cout << max(n - idx1, idx2 - 1);
}
