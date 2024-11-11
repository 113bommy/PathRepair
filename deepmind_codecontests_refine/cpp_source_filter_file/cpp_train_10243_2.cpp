#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  int A = 0, B = 0, mx, i;
  cin >> a >> b;
  for (i = 0; i < a.size(); i++)
    if (a[i] == '1') A++;
  for (i = 0; i < b.size(); i++)
    if (b[i] == '1') B++;
  mx = A + A % 2;
  if (mx <= B)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
