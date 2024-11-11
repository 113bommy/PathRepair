#include <bits/stdc++.h>
using namespace std;
int main() {
  int left = 0;
  int right = 0;
  int a;
  cin >> a;
  for (int i = 0; i < a; i++) {
    int b;
    cin >> b;
    if (b == 0) continue;
    if (b > 0)
      left++;
    else
      right++;
  }
  a++;
  a /= 2;
  if (left >= a) {
    cout << 1 << "\n";
  } else if (right >= a) {
    cout << -1 << "\n";
  } else
    cout << 0 << "\n";
}
