#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, d;
  scanf("%d", &n);
  string a;
  cin >> a;
  for (i = n; i > 1; i--) {
    if (n % i == 0) {
      reverse(a.begin(), a.begin() + i);
    }
  }
  cout << a << "\n";
  return 0;
}
