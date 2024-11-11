#include <bits/stdc++.h>
using namespace std;
int a[13] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292, 341};
int main() {
  long long n, m, ans;
  cin >> n;
  cout << (n <= 12 ? a[n] : a[12] + (n - 12) * 49);
  return 0;
}
