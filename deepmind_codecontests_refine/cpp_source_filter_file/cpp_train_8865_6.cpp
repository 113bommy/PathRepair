#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    bool flg = true;
    if (k % 3 == 0) {
      int tmp = n % (k + 1);
      if (tmp % 3 == 0 && tmp != k) flg = false;
    } else {
      if (n % 3 == 0) flg = false;
    }
    puts(flg ? "Alice" : "bob");
  }
}
