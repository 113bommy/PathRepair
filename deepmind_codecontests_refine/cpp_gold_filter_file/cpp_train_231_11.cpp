#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int cnt2 = 0, cnt3 = 0;
    while (n % 2 == 0) {
      n = n / 2;
      cnt2++;
    }
    while (n % 3 == 0) {
      n /= 3;
      cnt3++;
    }
    if (n == 1 && cnt3 >= cnt2) {
      cout << 2 * cnt3 - cnt2 << endl;
    } else {
      cout << "-1" << endl;
    }
  }
  return 0;
}
