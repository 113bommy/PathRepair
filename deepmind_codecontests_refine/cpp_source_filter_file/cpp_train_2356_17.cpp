#include <bits/stdc++.h>
using namespace std;
int main() {
  int x = 0;
  int y = 0;
  cin >> x;
  int a[x];
  for (int i = 0; i < x; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < x; i++) {
    if (a[i] > a[i + 1] && a[i] > a[i - 1]) {
      y++;
    }
    if (a[i] < a[i + 1] && a[i] < a[i - 1]) {
      y++;
    }
  }
  cout << y;
  return 0;
}
