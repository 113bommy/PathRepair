#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, energy = 0, res = 0, h = 0;
  cin >> n;
  int inp[n];
  for (int i = 0; i < n; i++) {
    cin >> inp[i];
  }
  for (int i = 0; i < n; i++) {
    if (inp[i] > h + energy) {
      res += inp[i] - h + energy;
      energy = 0;
    } else {
      energy += h - inp[i];
    }
    h = inp[i];
  }
  cout << res;
  return 0;
}
