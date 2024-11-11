#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);
  if (!(n & 1))
    cout << -1;
  else {
    int num = 0;
    for (int i = 0; i < n; i++) {
      a[i] = num;
      b[i] = num + 1;
      if (b[i] == n) b[i] = 0;
      c[i] = (a[i] + b[i]) % n;
      num += 2;
      if (num > n) num = 1;
    }
    for (auto x : a) cout << x << " ";
    cout << "\n";
    for (auto x : b) cout << x << " ";
    cout << "\n";
    for (auto x : c) cout << x << " ";
  }
}
