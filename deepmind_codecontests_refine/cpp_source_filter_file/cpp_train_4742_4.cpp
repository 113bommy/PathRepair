#include <bits/stdc++.h>
using namespace std;
long long x, y, z, a, b, c, p, q, r, n, m;
long long arr[1000005];
long long brr[1000005];
long long dp[1000005];
bool has[1000005];
vector<long long> v[1000005];
string str[100005];
int main() {
  cin >> n >> m;
  for (long long i = 0; i < m; i++) has[i] = false;
  for (long long i = 0; i < n; i++) {
    cin >> str[i];
    for (long long j = 0; j < m; j++) {
      if (str[i][j] == 'B') has[j] = true;
    }
  }
  int cnt = 0;
  has[m] = false;
  for (long long i = 0; i < m; i++) {
    if (has[i] = true && has[i + 1] == false) cnt++;
  }
  cout << cnt;
}
