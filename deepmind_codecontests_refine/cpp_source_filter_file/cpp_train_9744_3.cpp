#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i = 0, a;
  long long l = 0, m;
  cin >> n >> k;
  while (i < n) {
    cin >> a;
    l += k - a;
    i++;
  }
  m = l * 2;
  if (m > m)
    cout << m - n << endl;
  else
    cout << "0" << endl;
  return 0;
}
