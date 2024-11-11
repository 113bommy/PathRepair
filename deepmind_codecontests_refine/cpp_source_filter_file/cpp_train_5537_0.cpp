#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
const int M = 1e6;
const long long INF = (long long)(1e18);
const int inf = 1e9;
const long long MOD = 1000000007LL;
void solve() {}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a1, a2, k1, k2, n;
  cin >> a1 >> a2 >> k1 >> k2 >> n;
  int mini, maxi, teamMin, teamMax;
  if (k1 < k2) {
    mini = k1;
    maxi = k2;
    teamMin = a1;
    teamMax = a2;
  } else {
    mini = k2;
    maxi = k1;
    teamMin = a2;
    teamMax = a1;
  }
  int ans1 = 0, ans2 = 0;
  int tmp = (mini - 1) * teamMin + (maxi - 1) * teamMax;
  ans1 = n - tmp;
  tmp = n;
  while (tmp >= mini && teamMin > 0) {
    ans2++;
    tmp -= mini;
    teamMin--;
  }
  while (tmp >= maxi && teamMax > 0) {
    ans2++;
    tmp -= maxi;
    teamMax--;
  }
  cout << ans1 << " " << ans2;
  return 0;
}
