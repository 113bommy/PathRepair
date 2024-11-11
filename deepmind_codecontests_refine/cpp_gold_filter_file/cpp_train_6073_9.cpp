#include <bits/stdc++.h>
using namespace std;
long long a[200005];
const int mod = 998244353;
int INF = 1e9;
bool flag2[1000005], v2[1000005];
void primes(int n) {
  for (int i = 2; i <= n; i++) {
    if (v2[i]) continue;
    for (int j = i; j <= n / i; j++) v2[i * j] = 1;
  }
}
int main() {
  vector<int> ans;
  primes(1e6);
  for (int i = 13; i <= 1e6; i++) {
    if (flag2[i] == 1) continue;
    int flag = 0;
    if (v2[i] == 1) flag = 1;
    long long tmp = i;
    vector<int> v;
    while (tmp > 0) {
      v.push_back(tmp % 10);
      tmp /= 10;
    }
    tmp = 0;
    for (int k = 0; k < v.size(); k++) {
      tmp = tmp * 10 + v[k];
    }
    if (v2[tmp] == 1) flag = 1;
    if (flag == 0 && i != tmp) {
      ans.push_back(i);
      ans.push_back(tmp);
      flag2[tmp] = true;
    }
  }
  sort(ans.begin(), ans.end());
  int t;
  cin >> t;
  cout << ans[t - 1];
}
