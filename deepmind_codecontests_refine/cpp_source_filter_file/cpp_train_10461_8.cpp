#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, w, sum = 0, val;
  cin >> k >> n >> w;
  for (int i = 1; i <= w; i++) {
    sum = sum + (i * k);
  }
  val = sum - n;
  if (val <= n) {
    cout << "0";
  } else {
    cout << val;
  }
  return 0;
}
