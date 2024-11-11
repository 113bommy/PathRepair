#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
void solve() {
  long long int n, m, mn, mx;
  cin >> n >> m >> mn >> mx;
  vector<long long int> a(m);
  for (auto i = 0; i < (m); i++) {
    cin >> a[i];
  };
  long long int x = *min_element(a.begin(), a.end());
  long long int y = *max_element(a.begin(), a.end());
  if (x < mn || y > mx) {
    cout << "Incorrect";
    return;
  }
  if (x != mn) a.push_back((mn));
  if (y != mx) a.push_back((mx));
  if (a.size() > n)
    cout << "Incorrect";
  else
    cout << "Correct";
}
void template1() {
  long long int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  cout << "\n";
  return 0;
}
