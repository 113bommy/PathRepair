#include <bits/stdc++.h>
using namespace std;
long long a, b;
int main() {
  cin >> a >> b;
  if (a > b)
    cout << b << " " << (a - b) / 2;
  else
    cout << a << " " << (b - a) / 2;
}
