#include <bits/stdc++.h>
using namespace std;
long long n, a, b;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a > b) {
      cout << b * (b + 1) / 2 << endl;
    } else {
      cout << a * (a - 1) / 2 + 1 << endl;
    }
  }
}
