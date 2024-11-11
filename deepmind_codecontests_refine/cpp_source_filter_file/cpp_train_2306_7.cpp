#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int n, third = 1;
int mmin = 1e9;
int main() {
  cin >> n;
  int counter = 0;
  while (n--) {
    ++counter;
    int val;
    cin >> val;
    if (counter == 3) third = val;
    mmin = min(mmin, val);
  }
  cout << 2 + (3 ^ mmin) << endl;
  return 0;
}
