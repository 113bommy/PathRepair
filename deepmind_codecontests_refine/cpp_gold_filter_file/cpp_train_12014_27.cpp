#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long k = 999999 - n;
  for (int i = 0; i < n; i++) {
    cout << k << " ";
    k += 2;
  }
  return 0;
}
