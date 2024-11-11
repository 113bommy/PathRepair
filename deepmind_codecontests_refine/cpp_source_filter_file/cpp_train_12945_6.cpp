#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  int n, k, t, j, i, a[200] = {0};
  while (cin >> c) a[c]++;
  for (i = 200; !a[i]; i--)
    ;
  for (j = 1; j <= a[i]; j++) cout << char(i);
}
