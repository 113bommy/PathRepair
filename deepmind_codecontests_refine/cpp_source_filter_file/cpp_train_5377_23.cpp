#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans;
  cin >> n;
  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      ans++;
    }
  }
  cout << ans;
}
