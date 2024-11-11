#include <bits/stdc++.h>
using namespace std;
int main() {
  int count;
  cin >> count;
  int *d = new int[count - 1];
  for (int i = 0; i < count - 1; i++) {
    cin >> d[i];
  }
  int a, b;
  cin >> a;
  cin >> b;
  int onC = 0;
  for (int i = a - 1; i < b - 1; i++) {
    onC += d[i];
  }
  cout << onC;
  return 0;
}
