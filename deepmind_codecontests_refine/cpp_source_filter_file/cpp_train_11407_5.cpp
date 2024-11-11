#include <bits/stdc++.h>
using namespace std;
const int _size = 16;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int n, x;
int a[maxn];
map<int, long long> mmp;
set<int> mst;
int main() {
  mmp.clear();
  cin >> n >> x;
  long long p = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    mmp[a[i]]++;
    mst.insert(a[i]);
  }
  set<int>::iterator it = mst.begin();
  if (x)
    for (; it != mst.end(); ++it) {
      long long m = *it;
      p += mmp[m] * mmp[x ^ m];
    }
  else
    for (; it != mst.end(); it++) {
      long long m = mmp[a[(*it)]];
      p += m * (m - 1);
    }
  cout << p / 2 << endl;
  return 0;
}
