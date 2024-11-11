#include <bits/stdc++.h>
using namespace std;
int n, m, x = 2;
int main() {
  cin >> n >> m;
  if (n > 23) {
    cout << m << endl;
  } else {
    for (int i = 1; i < n; i++) {
      x = x * 2;
    }
    cout << m % x << endl;
  }
}
