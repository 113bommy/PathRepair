#include <bits/stdc++.h>
using namespace std;
int interact(int i, int j) {
  cout << "? " << i << ' ' << j << endl;
  int x;
  cin >> x;
  return x;
}
void solve() {
  int n;
  cin >> n;
  int a = interact(0, 2);
  int b = interact(0, 1);
  int c = interact(1, 2);
  vector<int> num(n + 1);
  num[1] = a - c;
  num[3] = a - b;
  num[2] = a - num[1] - num[3];
  for (int i = 4; i <= n; i++) {
    int x = interact(i - 1, i);
    num[i] = x - num[i - 1];
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << num[i] << " ";
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
