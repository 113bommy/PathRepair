#include <bits/stdc++.h>
using namespace std;
long long P = 1e9 + 7;
double PI = 3.141592653589793;
const int sqr = 500;
const int arrn = 2e5 + 5;
const int arrn2 = 6e3 + 5;
int n, bs1, bs2, diff;
vector<pair<int, int> > proc;
int ans[arrn] = {};
void send(int x) { cout << "+ " << x + 1 << endl; }
void run() {
  int k;
  int bef = 0;
  vector<int> proc;
  for (int i = n - 2; i >= 2; i--) {
    send(i);
    cin >> bef >> k;
    proc.push_back(k - bs2);
    bs2 = k;
  }
  int a, b, c;
  send(0);
  cin >> c >> a;
  a -= bs2;
  bs2 += a;
  if (c != bef) {
    for (int i = 1; i < n + 1; i++) {
      if (c - bef == i * (i - 1) / 2) {
        ans[0] = i;
        break;
      }
    }
  }
  send(1);
  cin >> bef >> k;
  proc.push_back(k - bs2);
  bs2 = k;
  send(0);
  cin >> c >> b;
  b -= bs2;
  if (ans[0] == 0) {
    if (c != bef)
      ans[0] = 1;
    else
      ans[0] = 0;
  }
  ans[2] = b - a - 1;
  ans[1] = a / (b - a);
  reverse(proc.begin(), proc.end());
  for (int i = 3; i < n; i++) {
    if (i == 3)
      ans[i] = (proc[i - 3] - (ans[i - 3] + 1) * (ans[i - 1] + 1)) /
               (ans[i - 1] + 1);
    else
      ans[i] = (proc[i - 3] - (ans[i - 1] + 1) * ans[i - 2] -
                ans[i - 1] * ans[i - 2]) /
               (ans[i - 1] + 1);
    if (i != n - 1) ans[i]--;
  }
}
void solve() {
  cin >> n >> bs1 >> bs2;
  run();
  cout << "! ";
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int T = 1;
  while (T--) solve();
}
