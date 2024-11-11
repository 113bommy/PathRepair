#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  cout << (n / 2 - (n / 2) % (k + 1)) / (k + 1) << " "
       << ((n / 2 - (n / 2) % (k + 1)) / (k + 1)) * k << " "
       << n - (n / 2 - (n / 2) % (k + 1)) << endl;
}
