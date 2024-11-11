#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long x, y;
  cin >> x >> y;
  long long a = abs(1 - x) + abs(1 - y);
  long long b = abs(n - x) + abs(n - y);
  if (a >= b)
    cout << "White" << endl;
  else if (a < b)
    cout << "Black" << endl;
}
