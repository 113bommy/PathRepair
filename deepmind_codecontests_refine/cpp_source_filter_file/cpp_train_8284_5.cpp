#include <bits/stdc++.h>
const long long int mod = 1000000007;
const double pi = acos(-1.0);
using namespace std;
int main() {
  string str;
  cin >> str;
  long long int len;
  len = str.length();
  long long int arr[len];
  long long int bcount = 0;
  long long int hi;
  hi = pow(10, 9) + 7;
  long long int sum;
  sum = 0;
  bcount = 0;
  long long int i;
  for (i = len - 1; i >= 0; --i) {
    if (str[i] == 'b') {
      bcount++;
      if (bcount >= hi) bcount -= hi;
    } else {
      sum += bcount;
      if (sum >= bcount) sum -= hi;
      bcount += bcount;
      if (bcount >= hi) bcount -= hi;
    }
  }
  cout << sum << endl;
  return 0;
}
