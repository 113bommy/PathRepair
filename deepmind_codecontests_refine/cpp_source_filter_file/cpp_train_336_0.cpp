#include <bits/stdc++.h>
using namespace std;
long long int dx[] = {0, 1, 0, -1};
long long int dy[] = {1, 0, -1, 0};
long long int dxx[] = {0, 1, 0, -1, 1, 1, -1, -1};
long long int dyy[] = {1, 0, -1, 0, 1, -1, 1, -1};
long long int solve() {
  long long int cnt = 0;
  return cnt;
}
bool cmp(long long int a, long long int b) { return a > b; }
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t;
  long long int n;
  cin >> n;
  long long int ans = n;
  long long int ans1 = 1;
  for (int i = 1; i < n; i++) {
    ans *= i;
    ans %= 1000000007;
    ans1 *= 2;
    ans1 %= 1000000007;
  }
  if (ans - ans1 < 0) {
    cout << 1000000007 - (ans - ans1) % 1000000007 << endl;
  } else
    cout << (ans - ans1) % 1000000007 << endl;
}
