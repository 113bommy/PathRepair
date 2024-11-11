#include <bits/stdc++.h>
using namespace std;
int n, a, i;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    (a % 2 == 0) ? cout << a - 1 : cout << a << " ";
  }
}
