#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  bool a[606];
  for (int i = 1; i <= 33; i++) a[i] = false;
  for (int i = 1; i <= 33; i++) a[i * (i + 1) / 2] = true;
  if (a[n])
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
