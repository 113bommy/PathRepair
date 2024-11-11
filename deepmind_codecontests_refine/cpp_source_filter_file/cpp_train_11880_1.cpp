#include <bits/stdc++.h>
using namespace std;
long long int n, a[110000];
void check(long long int c) {
  if (a[c] != c) check(a[c]);
  cout << c << " ";
}
int main() {
  cin >> n;
  a[1] = 1;
  for (int i = 2; i <= n; i++) cin >> a[i];
  check(n);
}
