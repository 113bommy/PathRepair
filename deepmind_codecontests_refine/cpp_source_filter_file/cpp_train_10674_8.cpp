#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  cin >> n;
  int q = n / 7;
  int d = n % 7;
  cout << min(d - 5, 2) + q * 2 << " " << min(d, 2) + q * 2;
}
