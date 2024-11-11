#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  int k;
  cin >> n >> k;
  long long num = 0;
  long long idx = -1;
  long long todie = n;
  for (int i = 0; i < k; ++i) {
    long long x;
    cin >> x;
    if (n % x < todie) {
      todie = n % x;
      idx = i + 1;
      num = n / x;
    }
  }
  cout << idx << ' ' << num;
  return 0;
}
