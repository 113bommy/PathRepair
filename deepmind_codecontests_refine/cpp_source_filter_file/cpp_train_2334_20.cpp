#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[17];
  int n, x = 1, sl[10];
  for (int i = 0; i < 10; i++) sl[i] = 0;
  cin >> n;
  for (int i = 0; i < 16; i++) {
    cin >> a[i];
    if (a[i] != '.') sl[a[i]]++;
  }
  n *= 2;
  for (int i = 0; i < 10; i++)
    if (sl[i] > n) x = 0;
  if (x == 0)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
