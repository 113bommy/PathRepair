#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, i;
  cin >> n;
  if (n % 2 == 0)
    s = n / 2;
  else
    s = -((n + 1) / 2);
  cout << s << endl;
}
