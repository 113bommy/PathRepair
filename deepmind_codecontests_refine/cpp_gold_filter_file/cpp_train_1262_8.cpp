#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(0);
  long long n;
  cin >> n;
  long long cnt = 0;
  set<long long> ans;
  ans.insert(1);
  for (long long i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      long long cnt = 0;
      long long z = (n / i);
      if (z % 2 == 0) {
        cnt = (1 + i * (z - 1) + 1) * (z / 2);
      } else
        cnt = (1 + i * (z - 1) + 1) * ((z - 1) / 2) + (i * (z / 2) + 1);
      ans.insert(cnt);
      cnt = 0;
      for (long long j = 1; j <= n; j += (n / i)) cnt += j;
      ans.insert(cnt);
    }
  }
  for (auto i : ans) cout << i << ' ';
  cout << endl;
}
