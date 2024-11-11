#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ad = 2;
  cin >> n;
  cout << ad << " ";
  for (int i = 2; i < n; i++) {
    ad += i;
    if (ad > n) ad -= n;
    cout << ad << " ";
  }
  return 0;
}
