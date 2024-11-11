#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> d;
  int largest = max(a, b);
  largest = max(largest, c);
  largest = max(largest, d);
  if (largest - a != 0) cout << largest - a << endl;
  if (largest - b != 0) cout << largest - b << endl;
  if (largest - c != 0) cout << largest - c << endl;
  if (largest - d != 0) cout << largest - d << endl;
}
