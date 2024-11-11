#include <bits/stdc++.h>
using namespace std;
long long int func(long long int a, long long int b, long long int k) {
  long long int pos = 0, i;
  if (a == b) {
    if (k % 2 == 0)
      return 0;
    else
      return a;
  }
  i = k / 2;
  if (i % 2 == 0) {
    pos = a * (i)-b * i;
    return pos;
  } else {
    pos = a * (i + 1) - b * i;
    return pos;
  }
}
int main() {
  long long int a, b, k, pos, t;
  cin >> t;
  while (t > 0) {
    cin >> a >> b >> k;
    pos = func(a, b, k);
    cout << pos << " ";
    t--;
  }
  return 0;
}
