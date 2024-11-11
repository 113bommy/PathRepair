#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 1;
const int inf = (int)1e9 + 1;
const long long big = (long long)1e18 + 1;
const int P = 239;
const int MOD = (int)1e9 + 9;
const int MOD1 = (int)1e9 + 9;
const double eps = 1e-9;
const double pi = atan2(0, -1);
const int ABC = 26;
int cnt_div[N];
vector<int> divs[N];
void init() {
  for (int x = 1; x < N; x++)
    for (int i = 1; i * i <= x; i++)
      if (x % i == 0) {
        cnt_div[x] += 1 + (i * i != x);
        divs[x].push_back(i);
        if (i * i != x) divs[x].push_back(x / i);
      }
}
long long pw[129][N];
void init_pw() {
  for (int x = 1; x < 128 + 1; x++) {
    pw[x][0] = 1;
    for (int j = 1; j < N; j++) pw[x][j] = pw[x][j - 1] * x % MOD;
  }
}
int a[N];
int pref[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  init();
  for (int i = 1; i < N; i++) sort(divs[i].begin(), divs[i].end());
  init_pw();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pref[a[i]]++;
  }
  for (int i = 1; i < N; i++) pref[i] += pref[i - 1];
  int ans = 1;
  for (int lcm = 2; lcm < N; lcm++) {
    long long cur = 1;
    for (int j = 0; j < (int)divs[lcm].size() - 1; j++) {
      int cnt = pref[divs[lcm][j + 1] - 1] - pref[divs[lcm][j] - 1];
      cur = cur * pw[j + 1][cnt] % MOD;
    }
    int cnt = n - pref[divs[lcm][(int)divs[lcm].size() - 1] - 1],
        cnt_less = (int)divs[lcm].size() - 1;
    cur = cur * (pw[cnt_less + 1][cnt] - pw[cnt_less][cnt] + MOD) % MOD;
    ans += cur;
    if (ans >= MOD) ans -= MOD;
  }
  cout << ans << "\n";
  return 0;
}
