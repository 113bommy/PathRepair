#include <bits/stdc++.h>
using namespace std;
int ask(int a, int b) {
  cout << "? " << a + 1 << " " << b + 1 << '\n';
  ;
  cout.flush();
  int k;
  cin >> k;
  return k;
}
void solve() {
  int n, p;
  cin >> n;
  vector<int> v(n);
  for (int i = 1; i < n; i++) {
    int a = ask(p, i);
    int b = ask(i, p);
    if (a > b) {
      v[p] = a;
      p = i;
    } else {
      v[i] = b;
    }
  }
  v[p] = n;
  cout << "! ";
  for (int i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  cout << '\n';
  ;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
