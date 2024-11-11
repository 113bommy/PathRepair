#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[500], b[500];
  cin >> a;
  cin >> b;
  if (!strcmp(a, b))
    cout << a;
  else
    cout << 1;
  return 0;
}
