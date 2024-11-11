#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    int ll, rr;
    cin >> ll >> rr;
    tot += rr - ll + 1;
  }
  cout << (k - tot % k) % k << "\n";
  return 0;
}
