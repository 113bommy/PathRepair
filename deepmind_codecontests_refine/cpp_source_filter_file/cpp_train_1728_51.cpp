#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
  cin >> n;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  long long temp = n - 2;
  long long ans = temp / 2;
  if (temp % 2) ans++;
  cout << ans << endl;
  return 0;
}
