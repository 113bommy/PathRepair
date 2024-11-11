#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int n_ = 10000000 + 100;
ll a, b, c, d, n, m, t, x, y, z, k;
int arr[1000011][2], dp[n_][2];
bool checked[10000001] = {false}, ok = true, no = false;
string AA = "YES", BB = "NO";
vector<ll> v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> t;
  for (int i = 2; i <= 10000000; i++) {
    if (checked[i]) continue;
    dp[i][0]++;
    for (int j = i + i; j <= 10000000; j += i) {
      if (j > 10000000) break;
      dp[j][0]++;
      dp[j][1] = i;
      checked[j] = true;
    }
  }
  for (int i = 0; i < t; i++) {
    cin >> n;
    ll x = n;
    if (dp[n][0] >= 2) {
      ll temp = 1;
      while (!(n % dp[x][1])) {
        n /= dp[x][1];
        temp *= dp[x][1];
      }
      arr[i][0] = temp;
    } else
      arr[i][0] = -1;
    if (arr[i][0] < 0)
      arr[i][1] = -1;
    else
      arr[i][1] = x / arr[i][0];
  }
  for (int i = 0; i < t; i++) {
    cout << arr[i][0] << ' ';
  }
  cout << '\n';
  for (int i = 0; i < t; i++) cout << arr[i][1] << ' ';
}
