#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const long long LINF = 2e18;
void inv(bool e);
template <typename T>
void die(T& a);
bool brute, alter;
int cnt_tests = 1;
int a, b, c, d;
void inp() { cin >> a >> b >> c >> d; }
int f(int val, int t) { return max(3 * val / 10, val - val / 250 * t); }
void solve() {
  if (f(a, c) == f(b, d))
    cout << "Tie";
  else {
    cout << (f(a, c) < f(b, d) ? "Vasya" : "Misha");
  }
}
void stress() {}
void naive() {}
void run();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (0) {
    freopen("stack.in", "r", stdin);
    freopen("stack.out", "w", stdout);
  }
  brute = false;
  for (int i = 0; (i < cnt_tests); i++) {
    run();
  }
  cerr << endl << "Time: " << clock() / 1000.0 << " ms";
  return 0;
}
void run() {
  if (!brute) {
    inp();
  } else {
    stress();
  }
  solve();
}
template <typename T>
void die(T& a) {
  cout << a;
  exit(0);
}
void inv(bool e) {
  if (!e) {
    vector<int> a;
    a[-1] += 1;
  }
}
