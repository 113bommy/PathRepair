#include <bits/stdc++.h>
using namespace std;
static const int OO = 0x3f3f3f3f, N = 2 * 1e5 + 10;
static const long long OOL = 0x3f3f3f3f3f3f3f3fLL;
int dx[] = {1, 1, 2, 2, 3, 3};
int dy[] = {2, 3, 1, 3, 1, 2};
int t;
long long n, ans;
vector<long long> v;
map<long long, int> m;
void leastdivisor(long long i) {
  for (long long j = 2; j * j <= i; ++j)
    if (i % j == 0) {
      bool flag = true, flag2 = true;
      for (int k = 0; k < ((int)(v).size()); ++k) {
        if (j % v[k] == 0) flag = false;
        if ((n / j) % v[k] == 0) flag2 = false;
      }
      if (flag) v.push_back(j);
      if ((i / j) != j && flag2) v.push_back(n / j);
    }
}
int main() {
  cin >> n;
  leastdivisor(n);
  if (((int)(v).size()) == 0) return cout << n, 0;
  ans = v[0];
  for (int i = 2; i <= v[0]; ++i) {
    for (int j = 1; j < ((int)(v).size()); ++j) {
      if ((i + v[j] - 1) % v[0] == 0) ans -= ((n - i) / v[j]);
    }
  }
  cout << max(1LL, ans);
}
