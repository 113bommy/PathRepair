#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long s = 0;
  cin >> n;
  long long a;
  int k = n - 1;
  for (int i = 0; i < n; i++) {
    cin >> a;
    s += a;
    s += (a - 1) * i;
  }
  cout << s;
  return 0;
}
