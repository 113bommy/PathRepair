#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int cowsToSwap = n / 2;
  int chaosAdd = (n - 2) * 2 + 1;
  long long res = 0;
  while (k > 0 && cowsToSwap > 0) {
    res += chaosAdd;
    chaosAdd -= 4;
    k--;
    cowsToSwap--;
  }
  cout << res;
}
