#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> chap(n);
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    chap[i] = l;
  }
  int k;
  cin >> k;
  int j = 0;
  while (chap[j] <= k) {
    ++j;
  }
  cout << n - j + 1 << "\n";
  return 0;
}
