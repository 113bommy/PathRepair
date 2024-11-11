#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    long long k, x;
    cin >> k >> x;
    k--;
    cout << x + k * 9 << endl;
  }
  return 0;
}
