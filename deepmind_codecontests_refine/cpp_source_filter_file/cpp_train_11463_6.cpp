#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int mod = 998244353;
const int inf = 0x3fffffff;
long long a, b;
vector<long long> res1, res2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b;
  long long sum = (a + b) << 1;
  long long p = sqrt(sum);
  if (p * (p + 1) > sum) p--;
  for (long long i = p; i >= 1; i--) {
    if (i >= a) {
      a -= i;
      res1.push_back(i);
    } else
      res2.push_back(i);
  }
  cout << res1.size() << endl;
  for (int i = 0; i < res1.size(); i++) cout << res1[i] << " ";
  cout << endl;
  cout << res2.size() << endl;
  for (int i = 0; i < res2.size(); i++) cout << res2[i] << " ";
  return ~~(0 - 0);
}
