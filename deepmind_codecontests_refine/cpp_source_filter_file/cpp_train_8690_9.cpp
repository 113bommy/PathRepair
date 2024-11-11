#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, l, r;
  cin >> n;
  l = 1;
  r = n;
  for (int i = 0; i < n; i++) {
    if (!i & 1)
      cout << l++ << " ";
    else
      cout << r-- << " ";
  }
}
