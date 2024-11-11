#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, a[n];
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p;
    a[p] = i;
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
}
