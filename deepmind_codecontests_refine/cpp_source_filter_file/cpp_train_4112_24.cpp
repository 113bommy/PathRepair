#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long ans = 0;
  cin >> n;
  for (int i = 9; i >= 0; i--) {
    int num = (int)(pow(10, i) + 0.1);
    if (n / num) {
      ans += (n - num + 1) * (i + 1);
      n = num - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
