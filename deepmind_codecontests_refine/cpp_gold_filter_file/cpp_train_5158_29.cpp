#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, e, i, j, has = 0;
  cin >> a >> b;
  has += (a / 5) * (b / 5);
  c = a / 5;
  d = b / 5;
  if (a % 5 >= 1) c++;
  if (b % 5 >= 4) d++;
  has += (c * d);
  c = a / 5;
  d = b / 5;
  if (a % 5 >= 2) c++;
  if (b % 5 >= 3) d++;
  has += (c * d);
  c = a / 5;
  d = b / 5;
  if (a % 5 >= 3) c++;
  if (b % 5 >= 2) d++;
  has += (c * d);
  c = a / 5;
  d = b / 5;
  if (a % 5 >= 4) c++;
  if (b % 5 >= 1) d++;
  has += (c * d);
  cout << has << "\n";
}
