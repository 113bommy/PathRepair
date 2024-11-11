#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int k = 1000000;
  for (long long int i = n; i >= 1; i--) {
    cout << k - i << " ";
  }
  return 0;
}
