#include <bits/stdc++.h>
using namespace std;
int arr[12];
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int cuenta = 0;
  for (int i = b + b; i <= c; i += b) {
    if (i > a) {
      cout << i - a << " ";
      cuenta++;
    }
  }
  if (cuenta == 0) cout << -1 << endl;
}
