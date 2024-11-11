#include <bits/stdc++.h>
using namespace std;
bool comp(int a, int b) { return a > b; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1, j = 1; i <= n; i++, j += 2) cout << "1 ";
    cout << "\n";
  }
  return 0;
}
