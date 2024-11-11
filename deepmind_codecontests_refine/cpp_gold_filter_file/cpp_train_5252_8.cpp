#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int a, b, c, one = 0, two = 0, zero = 0;
  cin >> a;
  for (b = 0; b < a; b++) {
    cin >> c;
    if (c % 3 == 0)
      zero++;
    else if (c % 3 == 1)
      one++;
    else
      two++;
  }
  cout << (long long int)(zero / 2) + min(one, two) << endl;
}
