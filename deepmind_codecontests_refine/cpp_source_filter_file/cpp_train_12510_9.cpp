#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  double n, k;
  cin >> n >> k;
  int i = 1;
  int ans = 0;
  while (ans < n - i + k) {
    ans += i;
    i++;
  }
  cout << ans - k << endl;
  return 0;
}
