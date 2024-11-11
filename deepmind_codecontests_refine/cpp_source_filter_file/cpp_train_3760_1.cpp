#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f;
const int N = 2e5 + 10;
const long long mod = 998244353;
int n, m, t, sx, sy, k, sum, cnt, ans;
int r, c;
long long p[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  string s;
  string st;
  cout << 0 << " " << 1 << endl;
  cin >> st;
  int l = 0, r = 1e9;
  for (int i = 1; i < n; i++) {
    int mid = (l + r) >> 1;
    cout << mid << " " << 1 << endl;
    cin >> s;
    if (s == st)
      l = mid + 1;
    else
      r = mid - 1;
  }
  cout << l << " " << 0 << " " << r << " " << 2 << endl;
}
