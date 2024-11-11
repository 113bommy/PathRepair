#include <bits/stdc++.h>
using namespace std;
int k;
bool isLucky(int temp) {
  int lc = 0, t;
  while (temp) {
    t = temp % 10;
    if (t == 4 or t == 7) lc++;
    temp /= 10;
  }
  if (lc <= k) return true;
  return false;
}
void solve() {
  int n, temp, count;
  cin >> n >> k;
  while (n--) {
    cin >> temp;
    if (isLucky(temp)) count++;
  }
  cout << count;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
