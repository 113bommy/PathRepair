#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, arr[100009];
  cin >> a;
  for (b = 0; b < a; b++) {
    cin >> arr[b];
    if (b > 0 && b < a) {
      cout << arr[b] + arr[b - 1] << " ";
    }
    if (b == a - 1) {
      cout << arr[b];
    }
  }
}
