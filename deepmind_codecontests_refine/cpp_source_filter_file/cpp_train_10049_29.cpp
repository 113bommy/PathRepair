#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  long long int sum = 0;
  for (int i = 1; i <= 2 * k; i += 2) {
    sum += (n - i) + (n - i - 1);
  }
  cout << sum;
  return 0;
}
