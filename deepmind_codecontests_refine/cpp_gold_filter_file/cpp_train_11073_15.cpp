#include <bits/stdc++.h>
using namespace std;
int n, m, k, i, p;
int main() {
  cin >> n;
  if (n < 3) {
    cout << -1;
  } else {
    for (i = n; i >= 1; i--) {
      cout << i << " ";
    }
  }
}
