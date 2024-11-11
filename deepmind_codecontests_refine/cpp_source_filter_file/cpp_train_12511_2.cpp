#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  cout << ((3 + 2 * n) -
           sqrt((3 + 2 * n) * (3 + 2 * n) - 4 * (n * n + n - 2 * k))) /
              2;
  return 0;
}
