#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, ans1, ans2;
  cin >> n;
  if (n % 7 == 0) {
    ans1 = ans2 = n / 7 * 2;
  } else if (n % 7 == 1) {
    ans1 = n / 7 * 2 + 1;
    ans2 = n / 7;
  } else if (n % 7 > 1 && n % 7 <= 5) {
    ans1 = n / 7 * 2 + 2;
    ans2 = n / 7 * 2;
  } else if (n % 7 == 6) {
    ans1 = n / 7 * 2 + 2;
    ans2 = n / 7 * 2 + 1;
  }
  cout << ans2 << " " << ans1 << endl;
}
