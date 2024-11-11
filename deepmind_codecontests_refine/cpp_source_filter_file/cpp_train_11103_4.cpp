#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  string a;
  cin >> n >> a;
  k = n;
  for (int i = 0; i < n; i++) {
    if (a[i] != a[i + 1]) {
      k--;
      i++;
    }
  }
  cout << k + 1;
}
