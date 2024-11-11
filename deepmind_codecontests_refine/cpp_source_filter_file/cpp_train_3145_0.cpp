#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
long long n;
bool took[MAXN];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  vector<long long> v;
  cin >> n;
  bool seen = 0;
  for (int i = 1; i <= n; i++) {
    long long cu;
    cin >> cu;
    if (cu == -1) {
      seen = 1;
    } else {
      if (seen)
        v.push_back(cu);
      else
        v.push_back(0);
    }
  }
  long long ans = v[n - 2];
  took[n - 2] = 1;
  long long cant = 0;
  for (int i = n / 2; i > 0; i /= 2) {
    cant += i;
    long long cut = n - 2;
    for (int j = n - cant - 1; j < n; j++)
      if (!took[j])
        if (v[cut] > v[j] || cut == n - 2) cut = j;
    ans += v[cut];
    took[cut] = 1;
  }
  cout << ans << endl;
}
