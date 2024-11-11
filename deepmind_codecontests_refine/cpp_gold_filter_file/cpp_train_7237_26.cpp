#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a;
  cin >> n >> a;
  long long int ans;
  if (a % 2 != 0) {
    ans = (a + 1) / 2 - 1;
  } else {
    ans = n / 2 - (a / 2);
  }
  cout << ans + 1 << endl;
}
