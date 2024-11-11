#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long ans = 0;
  for (int i = 0; i < (int)n; ++i) {
    long long a;
    cin >> a;
    ans = ans + (i + 1) * a;
  }
  cout << ans;
  return 0;
}
