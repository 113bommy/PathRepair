#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int a, b;
  cin >> a >> b;
  int temp;
  if (a < b) temp = a, a = b, b = temp;
  cout << a - b << " " << (a - b) / 2 << endl;
}
