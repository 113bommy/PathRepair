#include <bits/stdc++.h>
using namespace std;
int check(int k) {
  int ans;
  if (k <= 9) {
    ans = k;
  } else if (k < 190) {
    k = k - 9;
    int g = (k - 1) / 2 + 10;
    if (k % 2 == 0)
      ans = g % 10;
    else
      ans = g / 10;
  } else if (k < 2890) {
    k = k - 189;
    int g = (k - 1) / 3 + 100;
    if (k % 3 == 0)
      ans = g % 10;
    else if (k % 3 == 2)
      ans = (g / 10) % 10;
    else
      ans = g / 100;
  } else {
    k = k - 2889;
    int g = (k - 1) / 4 + 1000;
    if (k % 4 == 0)
      ans = g % 10;
    else if (k % 4 == 2)
      ans = (g / 100) % 10;
    else if (k % 4 == 3)
      ans = (g / 10) % 10;
    else
      ans = g / 1000;
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  cout << check(n);
}
