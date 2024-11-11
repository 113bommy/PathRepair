#include <bits/stdc++.h>
using namespace std;
void filo() {}
void fastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int N = 2222222, M = 12222222;
const int mod = 1e9 + 7;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dx1[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy1[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
long long child[200001];
void solve() {
  long long a, b;
  cin >> a >> b;
  cout << (a ^ b) << "\n";
}
int main() {
  filo();
  fastIO();
  int t;
  cin >> t;
  while (t-- > 0) solve();
  ;
  return 0;
}
