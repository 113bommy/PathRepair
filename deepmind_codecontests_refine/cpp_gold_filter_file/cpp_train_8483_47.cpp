#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a;
  cin >> b;
  if (a + b < 2) {
    cout << 0 << 0;
  } else {
    int diff = min(a, b);
    cout << diff << " ";
    int same = (max(a, b) - diff) / 2;
    cout << same;
  }
}
