#include <bits/stdc++.h>
using namespace std;
int power(int x, int y) {
  int a = x;
  for (int i = 0; i < y; i++) {
    x = x * a;
  }
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int c = 2, c2 = 1, c3 = 0;
  int sum = 0;
  int x;
  cin >> x;
  while (true) {
    c3++;
    if (sum == x) {
      cout << c3;
      break;
    } else if (sum > x) {
      cout << c3 - 1;
      break;
    }
    c2 += c;
    sum += c2;
    c++;
  }
  return 0;
}
