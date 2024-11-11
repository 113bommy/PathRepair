#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, coverd = 0, st, en;
  cin >> n >> k;
  while (n--) {
    cin >> st >> en;
    coverd += en - st + 1;
  }
  cout << (k - (coverd % k)) % k;
  return 0;
}
