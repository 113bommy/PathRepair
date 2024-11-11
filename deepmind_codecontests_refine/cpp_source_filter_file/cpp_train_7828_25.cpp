#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[110], b[110] = {0}, s = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
  }
  for (int i = 0; i < n; i++) {
    s += b[i] / 2;
  }
  cout << s / 2;
  return 0;
}
