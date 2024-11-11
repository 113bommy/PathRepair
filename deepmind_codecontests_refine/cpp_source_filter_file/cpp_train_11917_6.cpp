#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count = 0, h = 0;
  cin >> n;
  while (count < n) {
    h++;
    count += (h * (h - 1)) / 2;
  }
  cout << h - 1;
  return 0;
}
