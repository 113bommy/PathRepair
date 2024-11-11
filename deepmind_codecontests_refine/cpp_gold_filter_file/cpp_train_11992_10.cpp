#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long n, m = 0, i, j = 0;
int main() {
  cin >> n;
  string a;
  cin >> a;
  for (i = 0; i < n; i++) {
    if (a[i] == 'n') m++;
    if (a[i] == 'z') j++;
  }
  for (i = 0; i < m; i++) cout << "1 ";
  for (i = 0; i < j; i++) cout << "0 ";
}
