#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count = 0, h = 1;
  cin >> n;
  while (count < n) {
    h++;
    count += (h * (h - 1)) / 2;
  }
  cout << h - 2;
  return 0;
}
