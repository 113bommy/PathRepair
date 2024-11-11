#include <bits/stdc++.h>
using namespace std;
int main() {
  long long h, l;
  cin >> h >> l;
  cout.precision(20);
  cout << ((double)l * l - h * h) / (2 * h);
  return 0;
}
