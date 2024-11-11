#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 100005;
int n, m;
long long ans;
int a[N];
vector<int> v;
void solve(long long x) {
  if (x % 2 == 0) {
    solve(n + x / 2);
  } else {
    ans = (x + 1) / 2;
  }
}
int main() {
  cin >> n >> m;
  long long t;
  for (int i = 0; i < m; i++) {
    cin >> t;
    if (t % 2 == 0) {
      solve(t);
      cout << ans << endl;
    } else {
      cout << (t + 1) / 2 << endl;
    }
  }
  return 0;
}
