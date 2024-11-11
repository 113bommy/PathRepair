#include <bits/stdc++.h>
using namespace std;
long long n, r;
long long l[1000001];
long long t[1000001];
long long ans(0);
vector<pair<long long, long long> > Ans;
void Solve() {
  for (int i = 1; i <= n; i++)
    if (t[i] < l[i]) {
      cout << "-1";
      return;
    }
  long long p = 0;
  long long Time = 0;
  for (int i = 1; i <= n; i++) {
    if (p >= l[i]) {
      Time += l[i];
      p -= l[i];
    } else {
      Time += p;
      long long a = l[i] - p;
      long long b = t[i] - p;
      p = 0;
      if (a * 2 <= b)
        Time += a * 2;
      else {
        long long x = b - a;
        long long y = a - x;
        long long g = (y + r - 1) / r;
        ans += g;
        p = g * r - y;
        Ans.push_back(pair<long long, long long>(Time + x * 2, g));
        Time += b;
      }
    }
  }
  cout << ans << '\n';
  if (ans < 100000) {
    for (int i = 0; i < Ans.size(); i++) {
      for (int t = 0; t < Ans[i].second; t++)
        cout << Ans[i].first + t * r << " ";
    }
  }
}
void Enter() {
  cin >> n >> r;
  for (int i = 1; i <= n; i++) cin >> l[i];
  for (int i = 1; i <= n; i++) cin >> t[i];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  Enter();
  Solve();
}
