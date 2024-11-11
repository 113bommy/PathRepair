#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int cnt;
  if (n == 1) {
    printf("1\n");
    return 0;
  }
  if (!(n % 2)) {
    printf("0\n");
    return 0;
  }
  if (n == 3)
    cnt = 3;
  else if (n == 5)
    cnt = 15;
  else if (n == 7)
    cnt = 133;
  else if (n == 9)
    cnt = 2025;
  else if (n == 11)
    cnt = 37851;
  else if (n == 13)
    cnt = 1030367;
  else if (n == 15)
    cnt = 36362925;
  long long int ans = 1;
  for (int i = n; i >= 1; i--) ans = (ans * i) % 1000000007;
  ans = (ans * cnt) % 1000000007;
  cout << ans << endl;
  return 0;
}
