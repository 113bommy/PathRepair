#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    long long int p, q, r;
    cin >> p >> q >> r;
    cout << (p + q + r) / 2;
  }
}
