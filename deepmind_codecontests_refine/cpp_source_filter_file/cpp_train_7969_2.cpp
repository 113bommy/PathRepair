#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int ans = 1;
  if (n == 1 or n == 2) {
    cout << "-1";
  } else {
    if (n % 2 == 0) {
      ans = ((n / 4) * n) - 1;
      cout << (long long int)ans << " " << (long long int)ans + 2 << endl;
    } else {
      ans = ((n * n) - 1) / 2;
      cout << (long long int)ans << " " << (long long int)ans + 1 << endl;
    }
  }
  return 0;
}
