#include <bits/stdc++.h>
using namespace std;
int n, i, a, b, k;
set<int> x;
int main() {
  cin >> n;
  for (i = 1; i <= n * 2; i++) {
    cin >> a;
    b = x.size();
    x.insert(a);
    if (k < x.size()) {
      k = x.size();
    }
    if (b == x.size()) {
      x.erase(a);
    }
  }
  cout << k;
}
