#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;
const int N = 1e3 + 10;
int n, k;
int a[N];
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (a[1] & 1 && a[n] && 1 && (n & 1))
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
