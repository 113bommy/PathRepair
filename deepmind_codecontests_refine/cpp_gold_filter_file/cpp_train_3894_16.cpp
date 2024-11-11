#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e6 + 5;
const int MAXN = 505;
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long an = 0, an1, an2;
  an = an1 = an2 = 0;
  an = a / 3 + b / 3 + c / 3;
  long long mn = min(a, min(b, c));
  if (mn > 1) an1 = 1 + (a - 1) / 3 + (b - 1) / 3 + (c - 1) / 3;
  if (mn > 2) an2 = 2 + (a - 2) / 3 + (b - 2) / 3 + (c - 2) / 3;
  cout << max(an, max(an1, an2)) << endl;
}
