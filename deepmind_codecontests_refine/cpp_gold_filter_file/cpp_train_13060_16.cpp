#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  if (t % 2 == 0) {
    cout << 4 << " " << t - 4;
  } else {
    cout << 9 << " " << t - 9;
  }
  return 0;
}
