#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int count = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) count++;
  }
  cout << count << endl;
  for (int i = 1; i < n; i++) {
    if (a[i] == 1) cout << a[i - 1];
  }
  cout << a[n - 1];
  return 0;
}
