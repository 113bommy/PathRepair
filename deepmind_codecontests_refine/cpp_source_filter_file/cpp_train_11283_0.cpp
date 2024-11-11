#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int count = 0;
  cin >> n >> k;
  while (n--) {
    int a, b;
    cin >> a >> b;
    count += (b - a) + 1;
  }
  cout << k - (count % k) % k << endl;
  return 0;
}
