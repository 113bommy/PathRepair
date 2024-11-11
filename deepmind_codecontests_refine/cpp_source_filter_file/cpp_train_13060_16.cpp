#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  if (t % 2 == 0) {
    cout << t << " " << t - 4;
  } else {
    cout << t << " " << t - 9;
  }
  return 0;
}
