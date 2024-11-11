#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, dem = 0;
  cin >> a;
  for (int i = 0; i < a; i++) {
    int b, c, d;
    cin >> b >> c >> d;
    if (b == 1 && c == 1 || b == 1 && d == 1 || d == 1 && c == 1 ||
        d == 1 && b == 1 && c == 1)
      dem++;
  }
  cout << dem;
}
