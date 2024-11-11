#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long x = n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120 * n * (n - 1) *
                (n - 2) * (n - 3) * (n - 4);
  cout << x;
}
