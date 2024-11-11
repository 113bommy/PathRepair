#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, w, sum = 0, val;
  cin >> n >> k >> w;
  for (int i = 1; i <= w; i++) {
    sum = sum + (i * k);
  }
  val = sum - n;
  if (val < 0) {
    cout << "0";
  } else {
    cout << val;
  }
}
