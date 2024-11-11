#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (n > a + b) {
    cout << b + 1;
  } else {
    cout << n - b;
  }
}
