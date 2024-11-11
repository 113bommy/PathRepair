#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(101);
  int r, x;
  for (int i = 0; i < n; i++) {
    cin >> r;
    for (int i = 0; i < r; i++) {
      cin >> x;
      a[x]++;
    }
  }
  for (int i = 1; i <= 100; i++)
    if (a[i] == n) cout << i << " ";
  return 0;
}
