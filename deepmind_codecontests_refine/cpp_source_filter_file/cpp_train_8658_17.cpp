#include <bits/stdc++.h>
using namespace std;
long long int minres, maxres, n, l, r;
int main() {
  cin >> n >> l >> r;
  minres = n - l;
  for (int i = 0; i < l; i++) {
    minres += pow(2, i);
  };
  for (int i = 0; i < r; i++) {
    maxres += pow(2, i);
  };
  maxres += (n - r) * (pow(2, r - 1) - 1);
  cout << minres << ' ' << maxres;
}
