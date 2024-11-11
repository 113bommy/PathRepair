#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:167177216")
using namespace std;
const int INF = 1e9;
const long double eps = 1e-9;
const long long mod = INF + 7;
const long long INF64 = (long long)(INF) * (long long)(INF);
const int ddx[] = {-1, 1, 1, -1};
const int ddy[] = {1, 1, -1, -1};
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
const int dxh[] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int dyh[] = {1, -1, -2, -2, -1, 1, 2, 2};
const string dirs[] = {"RIGHT", "UP", "LEFT", "DOWN"};
const long double pi = acos(-1.0);
int main() {
  ios_base::sync_with_stdio(false);
  int k, a, b, v;
  cin >> k >> a >> b >> v;
  int ans = 0;
  while (a > 0) {
    b = max(b, 0);
    int cnt = min(b + 1, k);
    int can = min(a, cnt * v);
    ans++;
    a -= can;
    b -= cnt;
  }
  cout << ans << endl;
  return 0;
}
