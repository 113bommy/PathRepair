#include <bits/stdc++.h>
using namespace std;
int a, b[109], p[109], i1, k;
int main() {
  int max;
  cin >> a;
  for (int i = 0; i < 12; i++) cin >> b[i];
  sort(b, b + 12);
  i1 = 11;
  while (i1 > -1 && k < a) {
    k = k + b[i1];
    max++;
    i1--;
  }
  if (a == 0)
    cout << 0 << endl;
  else if (max == 12)
    cout << -1 << endl;
  else
    cout << max << endl;
}
