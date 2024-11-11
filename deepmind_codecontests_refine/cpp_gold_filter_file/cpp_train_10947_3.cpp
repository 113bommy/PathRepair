#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using piii = pair<int, pii>;
const ll INF = INT_MAX;
ll q, n, cnt;
bool chk;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> n;
    cnt = 0;
    chk = false;
    while (n != 1) {
      if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0) {
        chk = true;
        break;
      } else {
        if (n % 2 == 0) {
          n /= 2;
        } else if (n % 3 == 0) {
          n = n / 3 * 2;
        } else if (n % 5 == 0) {
          n = n / 5 * 4;
        }
        cnt++;
      }
    }
    if (chk)
      cout << -1 << '\n';
    else
      cout << cnt << '\n';
  }
  return 0;
}
