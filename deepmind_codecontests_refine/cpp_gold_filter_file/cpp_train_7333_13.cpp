#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 7;
const int maxm = 1e6 + 7;
const double pi = acos(-1.0);
long long di[maxn];
long long cnt = 0, num;
void help(long long x) {
  num = 0;
  long long tmp = (long long)sqrt(x);
  for (int i = 1; i <= tmp; i++) {
    if (x % i == 0) {
      di[num++] = i;
      if (x / i != i) di[num++] = x / i;
    }
  }
  sort(di, di + num);
}
void dfs(long long x, long long k) {
  if (cnt >= 100000) return;
  if (k == 0 || x == 1) {
    cout << x << " ";
    cnt++;
    return;
  }
  for (long long i = 0; i < num && di[i] <= x; i++) {
    if (x % di[i] == 0) dfs(di[i], k - 1);
    if (cnt >= 100000) return;
  }
}
int main() {
  long long x, k;
  cin >> x >> k;
  help(x);
  dfs(x, k);
  cout << endl;
  return 0;
}
