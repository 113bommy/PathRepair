#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  bool x = 0;
  cin >> n;
  for (int i = 1; i <= 31; i++)
    if (i * (i + 1) / 2 == n) x = 1;
  if (x)
    cout << "YES";
  else
    cout << "NO";
}
