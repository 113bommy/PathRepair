#include <bits/stdc++.h>
using namespace std;
int result[101];
void solve() {
  int ans = 1, sum = 1;
  result[1] = 1;
  for (int i = 2; i <= 50; i++) {
    ans += i;
    sum += ans;
    result[i] = sum;
  }
}
int main() {
  solve();
  int n;
  cin >> n;
  for (int i = 1; i <= 50; i++) {
    if (result[i] > n) {
      cout << --i;
      exit(0);
    }
  }
  return 0;
}
