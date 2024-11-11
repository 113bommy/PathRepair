#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int sum = n + m, cur = 1, tot = 0;
  while (tot + cur <= sum) {
    tot += cur;
    cur++;
  }
  vector<int> a, b;
  for (int i = cur - 1; i >= 1; i--) {
    if (n >= i) {
      n -= i;
      a.push_back(i);
    } else {
      if (m >= i) {
        m -= i;
        b.push_back(i);
      }
    }
  }
  cout << ((int)(a).size()) << "\n";
  for (int i = 0; i < ((int)(a).size()); i++) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << "\n";
  cout << ((int)(b).size()) << "\n";
  for (int i = 0; i < ((int)(b).size()); i++) {
    if (i > 0) cout << " ";
    cout << b[i];
  }
  cout << "\n";
}
