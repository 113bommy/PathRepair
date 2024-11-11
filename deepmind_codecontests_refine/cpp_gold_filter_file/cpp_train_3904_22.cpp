#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool w;
void input() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    if (x <= 5 || x > n - 5 || y <= 5 || y > m - 5) {
      w = 1;
      return;
    }
  }
}
void solve_output() { cout << (w ? "YES" : "NO") << "\n"; }
void test_case() {
  input();
  solve_output();
}
void pre() { return; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int q, multicase = 0, precalc = 0;
  if (precalc) pre();
  if (multicase)
    cin >> q;
  else
    q = 1;
  for (int i = 1; i <= q; ++i) test_case();
}
