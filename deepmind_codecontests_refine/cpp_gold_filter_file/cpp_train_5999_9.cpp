#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  int b[n + 100];
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(b, b + n);
  int x = b[n - 1] - 25;
  if (x > 0)
    cout << x;
  else
    cout << "0";
}
