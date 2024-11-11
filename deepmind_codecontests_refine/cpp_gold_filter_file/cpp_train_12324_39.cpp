#include <bits/stdc++.h>
using namespace std;
int main() {
  int X = 0, n;
  cin >> n;
  string a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    if (a[i] == "++X" || a[i] == "X++") X++;
  for (int i = 0; i < n; i++)
    if (a[i] == "--X" || a[i] == "X--") X--;
  cout << X;
  return 0;
}
