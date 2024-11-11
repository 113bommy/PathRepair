#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n == 1) cout << n, exit(0);
  cout << (n - 2) / 2 + (n - 2) % 2;
}
