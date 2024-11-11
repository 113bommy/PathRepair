#include <bits/stdc++.h>
using namespace std;
long long a, b, n, k, h;
int main() {
  int arr[3];
  cin >> arr[0] >> arr[1] >> arr[2];
  int y = 1, b = 2, r = 3;
  while (y < arr[0] && b <= arr[1] && r < arr[2]) {
    y++;
    r++;
    b++;
  }
  cout << y + b + r;
}
