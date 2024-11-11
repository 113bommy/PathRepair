#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
const long double PI = 3.14159265358979323846;
const long long MOD = 1e+9 + 7;
const long long INF = LLONG_MAX;
const int INFi = INT_MAX;
const long long N = 2e+5 + 8;
vector<long long> adj[N];
long long vis[N], vis2[N];
long long dx4[] = {0, 1, 0, -1}, dy4[] = {1, 0, -1, 0};
long long test_cases = 1;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
;
long long n, k, a[N], pre[N], first[N];
vector<long long> ans;
void MAIN(long long tc) {
  cin >> n;
  for (long long i = (1); i <= n; i++) {
    cin >> a[i];
    first[a[i]]++;
  }
  for (long long i = (1); i <= N - 1; i++) pre[i] = pre[i - 1] + first[i];
  long long lb = 0, rb = 0, mx = 0;
  for (long long i = (1); i <= N - 3; i++) {
    if (first[i] == 1 && first[i + 1] == 1) {
      lb = i;
      rb = i + 1;
      mx = 2;
    }
  }
  long long L = 0, R = 0;
  while (L < N && R < N) {
    while (first[R] == 0 && R < N) R++;
    L = R;
    while (first[R] != 0 && R < N) {
      if (first[R] == 1) {
        if (mx < pre[R] - pre[L - 1]) {
          mx = pre[R] - pre[L - 1];
          lb = L;
          rb = R;
        }
        L = R;
      }
      R++;
    }
    R--;
    if (mx < pre[R] - pre[L - 1]) {
      mx = pre[R] - pre[L - 1];
      lb = L;
      rb = R;
    }
    R++;
    L = R;
  }
  for (long long i = (rb); i >= lb; i--) {
    ans.push_back(i);
    first[i]--;
  }
  for (long long i = (lb); i <= rb; i++) {
    for (long long j = (1); j <= first[i]; j++) ans.push_back(i);
  }
  cout << ans.size() << " ";
  cout << "\n";
  ;
  ;
  for (auto it : ans) cout << it << " ";
  cout << "\n";
  ;
  ;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  ;
  for (long long i = (1); i <= test_cases; i++) {
    MAIN(i);
  }
}
