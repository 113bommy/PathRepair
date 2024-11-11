#include <bits/stdc++.h>
using namespace std;
int solve1(int i, int j) {
  cout << "? " << i << ' ' << j << endl;
  int x;
  cin >> x;
  return x;
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n + 1);
  int a, b, c;
  a = solve1(1, 3);
  b = solve1(2, 3);
  c = solve1(1, 2);
  v[1] = a - b;
  v[3] = a - c;
  v[2] = a - v[1] - v[3];
  for (int i = 4; i <= n; i++) {
    int x = solve1(i - 1, i);
    v[i] = x - v[i - 1];
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << v[i] << " ";
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
