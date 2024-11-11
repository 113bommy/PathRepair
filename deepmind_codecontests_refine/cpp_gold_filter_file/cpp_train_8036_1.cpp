#include <bits/stdc++.h>
using namespace std;
int dx[24] = {1, 0, -1, 0, 2,  0,  -2, 0,  -1, -1, -2, -2,
              1, 1, 2,  2, -1, -1, -2, -2, 1,  1,  2,  2};
int dy[24] = {0,  1,  0,  -1, 0, 2, 0, -2, -1, -2, -1, -2,
              -1, -2, -1, -2, 1, 2, 1, 2,  1,  2,  1,  2};
long long n, m, k;
long long arr[400010];
long long gcd(long long a, long long b) {
  while (b != 0) {
    long long r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  cin.ignore();
  for (int test_case = 0; test_case < t; ++test_case) {
    int flg = 0;
    long long ans1 = 0, ans2 = 0;
    string ans[2] = {"OBEY", "REBEL"};
    string s1, s2 = "";
    long long r, b, k;
    cin >> r >> b >> k;
    long long g = gcd(r, b);
    if (r > b) swap(r, b);
    if (g + (r * (k - 1)) < b) flg = 1;
    cout << ans[flg];
    cout << '\n';
  }
  return 0;
}
