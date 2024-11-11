#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long n;
  cin >> n;
  if (n % 2 == 0) {
    cout << n / 2 - 1;
    return 0;
  } else {
    cout << n / 2;
    return 0;
  }
}
