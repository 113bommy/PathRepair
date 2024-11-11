#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i = -1, k, l;
  cin >> k >> l;
  while (l % k == 0) {
    l /= k;
    i++;
  }
  if (i > 0 && l == 1)
    cout << "YES" << endl << i << endl;
  else
    cout << "NO" << endl;
}
