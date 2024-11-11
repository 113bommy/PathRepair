#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  const int limit = 100000;
  int frequancy[limit] = {0};
  cin >> n >> k;
  if (n == 1 && (k == 1 || k == 2))
    cout << "Yes";
  else if (k >= n)
    cout << "No";
  else {
    for (int i = 1; i <= k; i++) {
      frequancy[n % i]++;
      if (frequancy[n % i] > 1) {
        cout << "No";
        return 0;
      }
    }
    cout << "Yes";
  }
  return 0;
}
