#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, p, s;
  cin >> k >> n >> s >> p;
  cout << ((n * k + s - 1) / s + p - 1) / p;
  return 0;
}
