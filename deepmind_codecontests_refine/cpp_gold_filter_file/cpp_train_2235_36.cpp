#include <bits/stdc++.h>
using namespace std;
int x[] = {0, -1, 0, 1, -1, 1, -1, 1};
int y[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int MOD = 1e9 + 7, N = 2e5 + 5;
const double pi = acos(-1);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  vector<int> vec;
  int n, m;
  cin >> n >> m;
  int a = n, b = m;
  int mx = -1;
  while (a != 0) {
    mx = max(mx, a % 10);
    a /= 10;
  }
  while (b != 0) {
    mx = max(mx, b % 10);
    b /= 10;
  }
  mx++;
  int ans = 0, sum = 0;
  while (n != 0 || m != 0 || sum != 0) {
    sum += (m % 10) + (n % 10);
    sum /= mx;
    n /= 10, m /= 10;
    ans++;
  }
  cout << ans;
  return 0;
}
