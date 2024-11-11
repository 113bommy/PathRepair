#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, cnt;
  int brute[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  cin >> a >> b;
  for (int i = a; i <= b; i++) {
    int temp = i;
    while (temp > 0) {
      cnt += brute[temp % 10];
      temp /= 10;
    }
  }
  cout << cnt << endl;
  return 0;
}
