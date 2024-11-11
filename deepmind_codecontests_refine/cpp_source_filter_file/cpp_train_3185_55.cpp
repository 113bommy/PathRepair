#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, b, count;
  cin >> l >> b;
  while (l <= b) {
    l = l * 3;
    b = b * 2;
    count++;
  }
  cout << count;
}
