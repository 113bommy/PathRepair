#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (abs(c-a)<=d || abs(b-a)<=d&&abc(c-b)<=d) cout << "Yes" << endl;
  else cout << "No" << endl;
}