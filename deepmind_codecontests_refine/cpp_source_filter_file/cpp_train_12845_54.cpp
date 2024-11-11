#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  if (k >= n * (n - 1)) {
    cout << "no solution" << endl;
    return 0;
  }
  int diff = 5000;
  int curr = 0;
  for (int i = 0; i < (n); ++i) {
    cout << 0 << " " << curr << endl;
    --diff;
    curr += diff;
  }
  return 0;
}
