#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n];
  multiset<int> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  int m = *max_element(a, a + n);
  int c = 0;
  for (int i = 0; i < n; i++) {
    int su = a[i];
    for (int j = i + 1; j < n; j++) {
      su += a[j];
      if (su > m) break;
      if (s.find(su) != s.end()) {
        c++;
        s.erase(s.find(su));
      }
    }
  }
  cout << c << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
