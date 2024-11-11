#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef unsigned long long Ull;
const int maxn = (int)1e6 + 10;
const int MOD = (int)1e9 + 7;
const long long inf = 9223372036854775807;
const int N = 47;
int x[maxn], y[maxn];
long long gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int cnt = 0;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  priority_queue<int> pq;
  int n, a;
  int ans = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    pq.push(-a), pq.push(-a);
    ans += pq.top() + a;
    pq.pop();
  }
  cout << ans << endl;
  return 0;
}
