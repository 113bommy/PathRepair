#include <bits/stdc++.h>
#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")
using namespace std;
const int N = 1100;
const int MAXN = int(1e6) + 100;
const int Mmask = (1 << 20);
const int mod = int(1e9) + 7;
const long long MOD = (long long)(1e18) + 7ll;
int solution();
int main(int argc, char* const argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return solution();
}
int n, a[MAXN], ans;
int solution() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  for (int i = 2; i <= n; i++) {
    ans += (a[n] - a[i - 1] == a[i - 1]);
  }
  cout << ans;
  return 0;
}
