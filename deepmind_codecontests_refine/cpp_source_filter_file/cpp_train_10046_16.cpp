#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int nax = 1e6 + 10;
long long i, j, x, y, k, f, z, cnt;
vector<vector<long long>> a(100005);
map<long long, map<long long, long long>> m;
bool visited[500005];
FILE *input;
vector<long long> one;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    long long n, x1, y1, x2, y2, ans1, ans2, Min1, Min2, ans3, ans4;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    long long ans;
    if ((x1 == 0 && x2 == 0) || (x1 == n && x2 == n)) {
      ans = abs(y2 - y1);
    } else if ((y1 == 0 && y2 == 0) || (y1 == n && y2 == n)) {
      ans = abs(x2 - x1);
    } else if ((x1 == 0 && x2 == n) || (x1 == n && x2 == 0)) {
      ans = min(n + (y1 + y2), n + ((n - y1) + (n - y2)));
    } else if ((y1 == 0 && y2 == n) || (y1 == n && y2 == 0)) {
      ans = min(n + (x1 + x2), n + ((n - x1) + (n - x2)));
    } else if ((x1 == 0 && y2 == n)) {
      ans = (n - y1) + x2;
    } else if (x1 == 0 && y2 == 0) {
      ans = y1 + x2;
    } else if (x1 == n && y2 == n) {
      ans = (n - y1) + (n - y1);
    } else if (x1 == n && y2 == 0) {
      ans = y1 + x2;
    } else if (y1 == 0 && x2 == 0) {
      ans = x1 + y2;
    } else if (y1 == 0 && x2 == n) {
      ans = n - x1 + y2;
    } else if (y1 == n && x2 == 0) {
      ans = x1 + (n - y2);
    } else if (y1 == n && x2 == n) {
      ans = (n - x1) + (n - y2);
    }
    cout << ans << endl;
  }
  return 0;
}
