#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio();
  long long a;
  cin >> a;
  long long num = 0, sm = 1;
  long long b = a;
  while (b > 0) {
    num++;
    sm *= 10;
    b /= 10;
  }
  sm /= 10;
  long long out = (a / sm + 1) * sm;
  cout << out - a << endl;
  return 0;
}
