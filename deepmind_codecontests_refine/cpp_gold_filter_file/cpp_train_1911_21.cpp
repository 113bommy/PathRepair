#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60000000")
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
double const pi = 3.1415926535897932384626433832795;
int const inf = (int)1e9;
long long const inf64 = (long long)4e18;
const string name = "b";
const int NMAX = 10010;
int n, a[NMAX], ans;
vector<int> seg[NMAX];
int main() {
  cin >> n;
  for (int i = 0; i < (int)n; i++) scanf("%d", &a[i]);
  ans = 0;
  for (int i = 0; i < (int)n; i++) {
    for (int j = 0; j < (int)n + 1; j++) seg[j].clear();
    for (int j = 0; j < (int)n; j++) seg[max(0, j - a[j])].push_back(j);
    int now = 0, idx = 0, last = -1;
    while (idx < n - 1) {
      now++;
      int tmp = idx;
      for (int j = last + 1; j <= tmp; ++j)
        for (int f = 0; f < (int)seg[j].size(); f++) idx = max(idx, seg[j][f]);
      last = tmp;
    }
    ans += now;
    for (int j = (int)n - 1; j >= 0; j--) a[j + 1] = a[j];
    a[0] = a[n];
  }
  cout << ans << endl;
  return 0;
}
