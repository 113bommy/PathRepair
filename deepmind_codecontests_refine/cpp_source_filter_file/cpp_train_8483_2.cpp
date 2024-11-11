#include <bits/stdc++.h>
using namespace std;
int getMin(int a, int b) {
  if (a <= b)
    return a;
  else
    return b;
}
int getMax(int a, int b) {
  if (a >= b)
    return a;
  else
    return b;
}
int main() {
  int a, b;
  cin >> a >> b;
  int min = getMin(a, b);
  int max = getMax(a, b);
  cout << min << (max - min) / 2;
  return 0;
}
