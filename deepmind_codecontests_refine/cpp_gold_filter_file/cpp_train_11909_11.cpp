#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < n; i++) cout << i << " ";
  cout << endl;
  for (int i = 0; i < n; i++) cout << i << " ";
  cout << endl;
  for (int i = 0; i < n; i++) {
    int x = i + i;
    x %= n;
    cout << x << " ";
  }
  return 0;
}
