#include <bits/stdc++.h>
using namespace std;
string vow = "aeiou";
int month[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
const long double pie = 3.1415926535897932384626;
const long long mod = 1e9 + 7;
void solve(int test_case) {
  int n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++)
      for (int k = j; k < n; k++) ans = max(ans, (v[i] | v[j] | v[j]));
  }
  cout << ans;
  cout << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}
