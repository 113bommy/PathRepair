#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const int INFMEM = 63;
const int INF = 1061109567;
const long long LINF = 4557430888798830399LL;
const double DINF = numeric_limits<double>::infinity();
const long long MOD = 1000000007;
const int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
const int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
const char dch[4] = {'R', 'L', 'D', 'U'};
const double PI = 3.141592653589793;
inline void open(string a) {
  freopen((a + ".in").c_str(), "r", stdin);
  freopen((a + ".out").c_str(), "w", stdout);
}
inline void fasterios() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int MAXN = 1e6;
int prime[MAXN + 5];
int isi[MAXN + 5];
int leftMost[MAXN + 5];
vector<int> bracket[MAXN + 5];
int main() {
  fasterios();
  prime[0] = 1;
  prime[1] = 1;
  for (int i = 2; i <= MAXN; i++) {
    if (prime[i]) continue;
    prime[i] = i;
    if (i > 1000) continue;
    for (int j = i * i; j <= MAXN; j += i) prime[j] = i;
  }
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> isi[i];
  }
  for (int i = 1; i <= n; i++) {
    char ch;
    cin >> ch;
    int cur = isi[i];
    leftMost[i] = i;
    if (cur == 1) continue;
    if (ch == '*') {
      leftMost[i] = i + 1;
      while (cur > 1) {
        bracket[prime[cur]].push_back(i);
        cur /= prime[cur];
      }
    } else {
      while (cur > 1) {
        if ((int)(bracket[prime[cur]]).size()) {
          leftMost[i] = min(leftMost[i], bracket[prime[cur]].back());
          bracket[prime[cur]].pop_back();
        } else
          leftMost[i] = 0;
        cur /= prime[cur];
      }
    }
  }
  leftMost[n + 1] = -1;
  stack<int> antri;
  antri.push(n + 1);
  long long ans = 0;
  for (int i = n; i >= 1; i--) {
    while (leftMost[antri.top()] > i) antri.pop();
    if (leftMost[i] < i) {
      while (leftMost[antri.top()] >= leftMost[i]) antri.pop();
      antri.push(i);
    }
    ans += antri.top() - i;
  }
  cout << ans << '\n';
}
