#include <bits/stdc++.h>
using namespace std;
void let_it_rip() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  let_it_rip();
  unsigned long long q, n, cnt;
  cin >> q;
  while (q--) {
    cnt = 0;
    cin >> n;
    if (n == 2)
      cout << 2 << endl;
    else {
      while (n % 2 != 0) {
        ++n;
        ++cnt;
      }
      cout << cnt << endl;
    }
  }
  return 0;
}
