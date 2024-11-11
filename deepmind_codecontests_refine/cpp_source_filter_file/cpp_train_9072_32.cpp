#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int ans = n / 2 + 1;
  cout << ans << "\n";
  for (int i = 1; i <= ans; i++) cout << 1 << " " << i << "\n";
  for (int i = 2; i <= ans; i++) cout << ans << " " << i << "\n";
}
int main() { solve(); }
