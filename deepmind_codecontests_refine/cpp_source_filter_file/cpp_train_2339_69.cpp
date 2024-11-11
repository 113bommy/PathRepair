#include <bits/stdc++.h>
using namespace std;
const long long inf = (1LL << 60) - 1;
set<long long> s;
long long x, y, n, k, q;
int bal(string p1, string p2) {
  if (p1 == p2) return 0;
  if (p1 == "rock" && p2 == "scissor") return 1;
  if (p1 == "scissor" && p2 == "paper") return 1;
  if (p1 == "paper" && p2 == "rock") return 1;
  return 0;
}
void solve() {
  string f, m, s;
  cin >> f >> m >> s;
  x = bal(f, m) + bal(f, s);
  y = bal(m, s) + bal(m, f);
  n = bal(s, m) + bal(s, f);
  if (x == 2 && y == 0 && n == 0)
    cout << "F"
         << "\n";
  else if (y == 2 && x == 0 && n == 0)
    cout << "M"
         << "\n";
  else if (n == 2 && x == 0 && y == 0)
    cout << "S"
         << "\n";
  else
    cout << "?"
         << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  ;
  solve();
  return 0;
}
