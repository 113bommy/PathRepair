#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (b < 0) {
    b = b % n;
    b += n;
  }
  if ((a + b) % n == 0)
    cout << n;
  else
    cout << (a + b) % n;
}
