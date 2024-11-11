#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int l, r, c = 0;
  int dist;
  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    dist += r - l + 1;
  }
  cout << (k - dist % k) % k;
}
