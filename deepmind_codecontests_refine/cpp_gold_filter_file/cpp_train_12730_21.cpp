#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int inf = 0x7fffffff;
const int mod = 998244353;
long long t, n, m, k, sum, cnt, ans;
struct node {
  int x, y;
};
bool cmp(node a, node b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
node e[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cout << 1 << " ";
    cout << endl;
  }
  return 0;
}
