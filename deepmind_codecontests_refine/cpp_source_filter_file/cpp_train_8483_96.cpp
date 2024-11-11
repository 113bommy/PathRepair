#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, max, min;
  cin >> a >> b;
  if (a <= b) {
    max = a;
    min = b;
  } else if (b <= a) {
    max = b;
    min = a;
  }
  cout << max << " " << (a - b) / 2;
}
