#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  int n = a.length();
  sort(a.begin(), a.end());
  int m = (n - 1) / 2;
  a.erase(0, m);
  cout << a[0] << "+";
  for (int i = 1; i < n - m; i++) {
    cout << "+" << a[i];
  }
}
