#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
const long long inf = 1e15;
const int mod = 1e6;
void faster() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
const long long N = 3e5 + 10;
vector<int> adj[N];
long long a[N];
long long solve(int a, int b) {
  if (a == b && a == 1) return 0;
  if (a == b)
    return inf;
  else {
    if (a < b) swap(a, b);
    return solve(a - b, b) + 1;
  }
}
int main() {
  faster();
  int n;
  cin >> n;
  long long ans = n - 1;
  for (int i = 1; i < n; i++) {
    ans = min(ans, solve(n, i));
  }
  cout << ans << endl;
}
