#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, g = 0;
  cin >> n;
  for (int i = 1; i <= n / 2; i++) {
    if ((n - i) % i == 0) g++;
  }
  cout << g;
  return 0;
}
