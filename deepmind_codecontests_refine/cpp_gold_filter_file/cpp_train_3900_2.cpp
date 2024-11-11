#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;
const char E = '\n';
const int N = 2001;
const int mod = 1e9 + 7;
mt19937_64 mt_rnd_64(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l, ll r) { return (mt_rnd_64() % (r - l + 1)) + l; }
int n, arr[N][N];
ll dp1[2 * N], dp2[2 * N];
ll maxval[2];
pair<int, int> pos[2];
inline void update(bool pairing, int x, int y, ll val) {
  if (val > maxval[pairing]) {
    maxval[pairing] = val;
    pos[pairing] = {x, y};
  }
  return;
}
inline void ciut(pair<int, int> pr) {
  cout << pr.first << " " << pr.second << " ";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  cin >> n;
  pos[0] = {1, 1};
  pos[1] = {1, 2};
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> arr[i][j];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp1[i + j] += arr[i][j];
      dp2[i - j + n] += arr[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      update((i + j) & 1, i, j, dp1[i + j] + dp2[i - j + n] - arr[i][j]);
    }
  }
  cout << maxval[0] + maxval[1] << E;
  ciut(pos[0]);
  ciut(pos[1]);
  return 0;
}
