#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, m;
  cin >> n >> m;
  cout << ((m + 4) / 5) * ((n + 1)) / 5 + ((m + 1) / 5) * ((n + 4) / 5) +
              ((m + 3) / 5) * ((n + 2) / 5) + ((m + 2) / 5) * ((n + 3) / 5) +
              (n / 5) * (m / 5) - 1;
}
