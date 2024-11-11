#include <bits/stdc++.h>
using namespace std;
int main() {
  long unsigned int n, now, m;
  cin >> n;
  if (n % 2) {
    cout << n / 2;
  } else {
    m = log2(n);
    cout << (n - pow(2, m)) / 2;
  }
}
