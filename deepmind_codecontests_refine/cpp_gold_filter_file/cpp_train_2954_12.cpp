#include <bits/stdc++.h>
using namespace std;
int n;
long long a[80010];
const int m = 890000;
int grundy[m];
int main() {
  ios_base::sync_with_stdio(0);
  for (int i = 0; i < (4); i++) grundy[i] = 0;
  int count[7] = {};
  int L = 2, R = 1, left, right;
  for (int i = 4; i < (m + 1); i++) {
    left = sqrt(sqrt(i)) - 1e-9 + 1;
    right = sqrt(i) + 1e-9;
    if (left == L + 1) {
      count[grundy[L]]--;
      L++;
    }
    if (right == R + 1) {
      R++;
      count[grundy[R]]++;
    }
    while (count[grundy[i]] > 0) grundy[i]++;
  }
  cin >> n;
  for (int i = 0; i < (n); i++) cin >> a[i];
  sort(a, a + n);
  L = 2, R = 1;
  fill(count, count + 7, 0);
  long long ans = 0, g;
  for (int i = 0; i < (n); i++) {
    left = sqrt(sqrt(a[i])) - 1e-9 + 1;
    right = sqrt(a[i]) + 1e-9;
    while (L < left) {
      count[grundy[L]]--;
      L++;
    }
    while (R < right) {
      R++;
      count[grundy[R]]++;
    }
    g = 0;
    while (count[g] > 0) g++;
    ans ^= g;
  }
  cout << (ans ? "Furlo" : "Rublo");
}
