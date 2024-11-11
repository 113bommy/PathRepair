#include <bits/stdc++.h>
using namespace std;
void candy(int n) {
  int x, counts = 0, i = n;
  while (i--) {
    cin >> x;
    if (x % 2 != 0) {
      counts++;
    }
  }
  if (counts % 2 == 0) {
    cout << (n - counts);
  } else if (n == counts) {
    cout << n;
  } else {
    cout << "-1";
  }
}
int main() {
  int n;
  cin >> n;
  candy(n);
  return 0;
}
