#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long x[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x, x + n);
  for (int i = 0; i < n; i++) {
    cout << x[i] << " ";
  }
}
