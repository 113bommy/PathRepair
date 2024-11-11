#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, k;
int main() {
  cin >> n;
  if (n == 1) {
    cout << "1 1\n1\n";
  } else {
    cout << (n - 1) / 2 << " 2\n1 2\n";
  }
}
