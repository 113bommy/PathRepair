#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  int n, k, q, l = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> c >> q;
    if (c == '+')
      k += q;
    else {
      if (k >= q)
        k -= q;
      else
        l++;
    }
  }
  cout << k << ' ' << l;
  return 0;
}
