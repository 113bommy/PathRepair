#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  if ((n - 3) % 4 == 0 || n == 3 || n % 4 == 0) {
    cout << "0";
    return 0;
  }
  cout << "1";
  return 0;
}
