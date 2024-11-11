#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int k = 100000;
  for (long long int i = 1; i <= n; i++) {
    cout << k - i << " ";
  }
  return 0;
}
