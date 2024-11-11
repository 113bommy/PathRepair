#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    m[temp]++;
  }
  int ans = 0;
  for (auto i : m) ans ^= (i.second & 1);
  cout << (ans ? "Conan" : "Agasa");
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
