#include <bits/stdc++.h>
using namespace std;
int a, b, s;
int main() {
  cin >> a >> b >> s;
  a = abs(a);
  b = abs(b);
  if (s >= a + b)
    cout << "Yes";
  else if ((s - a - b) % 2 == 0)
    cout << "Yes";
  else
    cout << "No";
}
