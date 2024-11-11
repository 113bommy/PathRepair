#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> v(n);
  for (int i = 0; i < a; i++) {
    int x;
    cin >> x;
    --x;
    v[x] = 1;
  }
  for (int i = 0; i < b; i++) {
    int x;
    cin >> x;
    v[x] = 2;
  }
  for (int a : v) cout << a << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
