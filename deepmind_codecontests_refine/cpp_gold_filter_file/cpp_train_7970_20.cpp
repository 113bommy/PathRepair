#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int left = 240 - k;
  int i = 1, count = 0;
  while (left > 0) {
    if (count == n) break;
    left = left - i * 5;
    i++;
    if (left >= 0) count++;
  }
  cout << count;
}
