#include <bits/stdc++.h>
using namespace std;
long long n, a, maxi, cnt;
int k, id;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    cin >> a;
    if (maxi < (n / a) * a) {
      maxi = (n / a) * a;
      cnt = n / a;
      id = i;
    }
  }
  cout << id << ' ' << cnt;
  return 0;
}
