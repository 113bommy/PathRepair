#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  --n;
  int right, left, down, up;
  right = left = down = up = n / 4;
  n = n - up * 4;
  if (n != 0) {
    ++right;
    --n;
  }
  if (n != 0) {
    ++left;
    --n;
  }
  if (n != 0) {
    ++down;
    --n;
  }
  if (n != 0) {
    ++up;
    --n;
  }
  int centerx = 0, centery = 0;
  cout << centerx << " " << centery << endl;
  for (int i = 0; i < right; ++i) {
    cout << centerx + i + 1 << " " << centery << endl;
  }
  for (int i = 0; i < left; ++i) {
    cout << centerx - i - 1 << " " << centery << endl;
  }
  for (int i = 0; i < up; ++i) {
    cout << centerx << " " << centery + i + 1 << endl;
  }
  for (int i = 0; i < down; ++i) {
    cout << centerx << " " << centery - i - 1 << endl;
  }
  return 0;
}
