#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;
long long N, M, D;
long long dp[2][300003];
struct fire {
  long long a, b, t;
};
int dq[400003];
int frt, bck;
long long min(long long a, long long b) { return a < b ? a : b; }
long long max(long long a, long long b) { return a < b ? b : a; }
void pop_front() { ++frt; }
void pop_back() { --bck; }
void push_front(int val) { dq[--frt] = val; }
void push_back(int val) { dq[++bck] = val; }
bool empty() { return frt > bck; }
int front() { return dq[frt]; }
int back() { return dq[bck]; }
fire fires[303];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> N >> M >> D;
  for (int i = 1; i <= M; i++) {
    long long a, b, t;
    cin >> a >> b >> t;
    fires[i] = fire{a, b, t};
  }
  for (int i = 1; i <= M; i++) {
    long long L = min(2 * N, 2 * D * (fires[i].t - fires[i - 1].t) + 1);
    frt = 200002;
    bck = 200001;
    for (int j = N + 1; j <= 2 * N; j++) dp[(i + 1) % 2][j] = -infl;
    for (int j = 1; j <= 2 * N; j++) {
      while (!empty() && front() <= j - L) pop_front();
      while (!empty() && dp[(i + 1) % 2][back()] <= dp[(i + 1) % 2][j])
        pop_back();
      push_back(j);
      long long mx =
          dp[(i + 1) % 2][front()] + fires[i].b - abs(fires[i].a - (j - L / 2));
      if (0 < j - L / 2 && j - L / 2 <= N) dp[i % 2][j - L / 2] = mx;
    }
  }
  long long ans = -infl;
  for (int i = 1; i <= N; i++) ans = max(ans, dp[M % 2][i]);
  cout << ans;
  return 0;
}
