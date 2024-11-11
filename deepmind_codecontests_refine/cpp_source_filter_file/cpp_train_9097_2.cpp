#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long c = 1;
  while (n % c) {
    c *= 3;
  }
  cout << (n + (c - 1)) / c << endl;
}
