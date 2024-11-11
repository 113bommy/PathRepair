#include <bits/stdc++.h>
const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;
using namespace std;
string str;
int a[10];
int main(int argc, const char* argv[]) {
  a[0] = 1;
  a[1] = 6;
  a[2] = 1;
  a[3] = 2;
  a[4] = 2;
  a[5] = 3;
  a[6] = 1;
  a[7] = 4;
  a[8] = 0;
  a[9] = 1;
  cin >> str;
  if (str.size() == 2) {
    int ind1 = str[0] - '0';
    int ind2 = str[1] - '0';
    cout << 1 + a[ind1] + a[ind2] + a[ind1] * a[ind2];
    return 0;
  } else if (str.size() == 1) {
    int ind1 = str[0] - '0';
    cout << 1 + a[ind1];
    return 0;
  }
  return 0;
}
