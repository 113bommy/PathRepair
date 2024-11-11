#include <bits/stdc++.h>
using namespace std;
ifstream in("swaps.in");
ofstream out("swaps.out");
int n, t, a[505], b[505];
vector<pair<int, int>> p1, p2;
void input() {
  int i;
  in >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) cin >> b[i];
}
void solve() {
  int i;
  if (n % 2 == 1 && a[n / 2 + 1] != b[n / 2 + 1]) {
    cout << "No\n";
    return;
  }
  p1.clear();
  for (i = 1; i <= n / 2; i++)
    p1.push_back({min(a[i], a[n - i + 1]), max(a[i], a[n - i + 1])});
  p2.clear();
  for (i = 1; i <= n / 2; i++)
    p2.push_back({min(b[i], b[n - i + 1]), max(b[i], b[n - i + 1])});
  sort(p1.begin(), p1.end());
  sort(p2.begin(), p2.end());
  for (i = 0; i < p1.size(); i++) {
    if (p1[i] != p2[i]) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
}
int main() {
  in >> t;
  while (t--) {
    input();
    solve();
  }
}
