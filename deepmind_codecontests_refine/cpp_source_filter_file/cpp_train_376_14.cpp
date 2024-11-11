#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int l = (b - a) / 2;
  if ((b - a) % 2 == 0) {
    cout << l * (l + 1) << endl;
  } else {
    int temp = l * (l + 2) + 1;
    cout << temp << endl;
  }
}
