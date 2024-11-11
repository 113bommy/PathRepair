#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int current = 1;
  int left = m;
  while (left > 0) {
    if (left - current >= 0) {
      left = left - current;
    } else {
      break;
    }
    current++;
    if (current > n) {
      current = 1;
    }
  }
  cout << left << endl;
  return 0;
}
