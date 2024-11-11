#include <bits/stdc++.h>
using namespace std;
clock_t time_p = clock();
void Time() {
  time_p = clock() - time_p;
  cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
const int INF = 1e9 + 7;
long double pi = 3.1415926535897932;
const long long INF64 = 9e18;
const long long mod = 1e9 + 7;
const int mxN = 1e6;
void solve() {
  int n;
  cin >> n;
  n *= 2;
  stack<int> stk;
  int ans = 0;
  int lst = 0, need = 1;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (s == "add") {
      int x;
      cin >> x;
      stk.push(x);
    } else {
      if (!stk.empty()) {
        int x = stk.top();
        if (x == need) {
          stk.pop();
          need++;
          continue;
        }
        while (!stk.empty()) stk.pop();
        need++;
        ans++;
      } else
        need++;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.precision(15);
  cout.precision(15);
  cerr << fixed;
  cout << fixed;
  int t;
  solve();
  Time();
  return 0;
}
