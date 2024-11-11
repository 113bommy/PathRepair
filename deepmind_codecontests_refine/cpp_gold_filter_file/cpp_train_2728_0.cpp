#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using db = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vl = vector<ll>;
void solve(vi v, int N) {
  for (int i = 1; i < N; i++) {
    if (abs(v[i] - v[i - 1]) >= 2) {
      cout << "YES\n" << i << " " << i + 1 << "\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  int T, N;
  cin >> T;
  while (T--) {
    cin >> N;
    vi v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    solve(v, N);
  }
  return 0;
}
