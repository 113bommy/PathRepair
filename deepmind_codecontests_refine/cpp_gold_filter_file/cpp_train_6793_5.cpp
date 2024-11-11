#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int N = 2e3 + 10;
const int M = 3e6 + 10;
const int maxn = 1e6 + 10;
const int mod = 1000173169;
const double eps = 1e-10;
const double pi = acos(-1.0);
int n, p;
int a[N], b[N];
vector<int> ans;
bool check(int x) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    b[i] = a[i] - x + 1;
    if (b[i] <= 1) cnt++;
  }
  if (cnt >= p) return 0;
  for (int i = n; i; i--) {
    if (b[i] <= 1) break;
    int t = n - b[i] + 1 - (n - i);
    if (t <= 0 || t % p == 0) return 0;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> p;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= 2000; i++) {
    if (check(i)) ans.push_back(i);
  }
  cout << ((int)ans.size()) << '\n';
  for (int v : ans) cout << v << ' ';
  cout << '\n';
  return 0;
}
