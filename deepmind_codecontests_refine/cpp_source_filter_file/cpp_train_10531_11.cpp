#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const long long SZ = 510, SSZ = 0, APB = 26, INF = 0x7FFFFFF, mod = 1000000007;
long long n, m;
void init() {
  cin >> n >> m;
  long long maxpos = 18;
  for (; m < (1LL << maxpos); --maxpos)
    ;
  vector<long long> res;
  long long val = 1LL << maxpos;
  for (long long i = 1; i < (1LL << n); ++i) {
    long long tmp = i & (val * 2 - 1);
    if (tmp < 1 || tmp > val || maxpos > n) {
      res.push_back(i & -i);
    }
  }
  cout << res.size() << endl;
  for (long long i = 0; i < res.size(); ++i) {
    if (i) cout << " ";
    cout << res[i];
  }
  cout << endl;
}
void work() {}
int main() {
  std::ios::sync_with_stdio(0);
  long long casenum;
  {
    init();
    work();
  }
  return 0;
}
