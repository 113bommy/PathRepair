#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int i = 1;
  long long int a[n];
  while (i <= n) {
    cin >> a[i];
    i++;
  }
  cout << n + 1 << endl;
  cout << 1 << " " << n << " " << 5600 << endl;
  i = 1;
  while (i <= n) {
    cout << 2 << " " << i << " " << a[i] + 5600 - i << endl;
    i++;
  }
}
