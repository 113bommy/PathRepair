#include <bits/stdc++.h>
using namespace std;
int p_mod(int a, int b) { return (b + (a % b)) % b; }
constexpr int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    a[i].second = i + 1;
    cin >> a[i].first;
  }
  sort(a.begin(), a.end());
  cout << (n + 1) / 2 << "\n";
  for (int i = 0; i < n; i += 2) cout << a[i].second << " ";
  cout << "\n" << n - (n + 1) / 2 << "\n";
  for (int i = 1; i < n; i += 2) cout << a[i].second << " ";
  cout << "\n";
  return 0;
}
