#include <bits/stdc++.h>
using namespace std;
int a[100];
int main() {
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[x % 3]++;
  }
  cout << a[0] + min(a[1], a[2]);
  return 0;
}
