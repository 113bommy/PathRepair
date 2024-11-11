#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  int x = 1;
  while (m >= x && n--) {
    x *= 2;
  }
  cout << m % x;
}
