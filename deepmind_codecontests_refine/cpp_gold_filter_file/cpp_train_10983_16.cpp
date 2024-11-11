#include <bits/stdc++.h>
using namespace std;
string lowe(string a) {
  for (int i = 0; i < a.size(); i++)
    if (a[i] > 64 && a[i] < 91) a[i] = a[i] + 32;
  return a;
}
string upper(string a) {
  for (int i = 0; i < a.size(); i++)
    if (a[i] > 96 && a[i] < 123) a[i] = a[i] - 32;
  return a;
}
int main() {
  string a;
  int q = 0, w = 0;
  cin >> a;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] > 96) q++;
    if (a[i] < 91) w++;
  }
  if (q >= w)
    a = lowe(a);
  else if (q < w)
    a = upper(a);
  cout << a;
}
