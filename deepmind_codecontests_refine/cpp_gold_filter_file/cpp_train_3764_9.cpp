#include <bits/stdc++.h>
using namespace std;
int main() {
  int n[4];
  for (int i = 0; i < 4; i++) {
    cin >> n[i];
  }
  int big = 0;
  for (int i = 0; i < 4; i++) {
    if (n[i] > big) {
      big = n[i];
    }
  }
  int nums[4];
  for (int i = 0; i < 4; i++) {
    nums[i] = big - n[i];
  }
  for (int i = 0; i < 4; i++) {
    if (nums[i] == 0) {
      continue;
    } else {
      cout << nums[i] << " ";
    }
  }
  return 0;
}
