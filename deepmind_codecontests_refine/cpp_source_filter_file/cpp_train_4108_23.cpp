#include <bits/stdc++.h>
using namespace std;
int a, b[100009], co[100009], d[100009];
int main() {
  cin >> a;
  for (int i = 1; i <= a; i++) cin >> b[i], co[b[i]]++;
  d[1] = co[1];
  for (int i = 2; i <= 100009; i++) d[i] = max(d[i - 1], d[i - 2] + co[i] * i);
  cout << d[100009] << endl;
  return 0;
}
