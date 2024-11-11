#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, y, c;
  cin >> n >> x >> y >> c;
  long long int up = x - 1;
  long long int down = n - x;
  long long int left = y - 1;
  long long int right = n - y;
  long long int result = 0;
  long long int i = 0;
  while (result < c) {
    long long int m = (2 * i * i) + (2 * i) + 1;
    long long int up1 = 0, down1 = 0, right1 = 0, left1 = 0;
    up1 = up - i;
    down1 = down - i;
    right1 = right - i;
    left1 = left - i;
    long long int up_temp = 0, down_temp = 0, left_temp = 0, right_temp = 0;
    long long int UR = 0, UL = 0, DR = 0, DL = 0;
    if (right1 < 0) right_temp = right1 * right1;
    if (left1 < 0) left_temp = left1 * left1;
    if (up1 < 0) {
      up_temp = up1 * up1;
      up1 = -up1;
      long long int temp = y + (up1 - 1) - n;
      if (temp > 0) UR = temp * (temp + 1) / 2;
      temp = y - (up1);
      if (temp < 0) {
        temp = -temp;
        UL = temp * (temp + 1) / 2;
      }
    }
    if (down1 < 0) {
      down_temp = down1 * down1;
      down1 = -down1;
      int temp = y + (down1 - 1) - n;
      if (temp > 0) DR = temp * (temp + 1) / 2;
      temp = y - (down1);
      if (temp < 0) {
        temp = -temp;
        DL = temp * (temp + 1) / 2;
      }
    }
    result =
        m - up_temp - down_temp - right_temp - left_temp + (UR + UL + DR + DL);
    i++;
  }
  cout << i - 1 << endl;
  return 0;
}
