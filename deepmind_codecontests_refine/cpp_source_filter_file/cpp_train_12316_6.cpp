#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int k, l, m, n, d;
  int s = 0;
  cin >> k;
  cin >> l;
  cin >> m;
  cin >> n;
  cin >> d;
  for (int i = 0; i < d; i++) {
    if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) s++;
  }
  cout << s << endl;
  return 0;
}
