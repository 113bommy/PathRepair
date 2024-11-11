#include <bits/stdc++.h>
using namespace std;
const int N = 50;
int n;
int a[N];
int main() {
  cin >> n;
  if (n < 3) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < n; i++) a[i] = n - i;
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  return 0;
}
