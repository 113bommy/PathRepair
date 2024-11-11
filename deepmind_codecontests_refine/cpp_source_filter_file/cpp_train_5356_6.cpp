#include <bits/stdc++.h>
using namespace std;
long long n, p, a[305];
bool l, r;
long long cnt, cnt1, cnt2, cnt3;
map<long long, long long> m;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> p >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    m[a[i] % 10]++;
    if (m[a[i] % 10] > 1) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
}
