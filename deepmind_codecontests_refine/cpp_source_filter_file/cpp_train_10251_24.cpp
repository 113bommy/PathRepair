#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double EPS = 1e-7;
const int inf = 1e8;
int main() {
  long long a;
  cin >> a;
  long long b = a / 2;
  if (a % 2) b += a;
  cout << b << endl;
}
