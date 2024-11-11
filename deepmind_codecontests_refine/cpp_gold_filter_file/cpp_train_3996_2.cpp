#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
const int ST = 100010;
const int ST1 = 1000010;
const long long MOD = 1000000007;
long long ABS(long long a) {
  if (a < 0)
    return a * (-1);
  else
    return a;
}
long long mas[ST];
int main() {
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> mas[i];
  vector<long long> ans;
  long long pred = 0;
  cin >> m;
  long long mxx = 0;
  for (int i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    a--;
    for (int j = a; j >= pred; j--) {
      mxx = max(mxx, mas[j]);
    }
    ans.push_back(mxx);
    mxx += b;
    pred = max(pred, a);
  }
  for (int i = 0; i < m; i++) cout << ans[i] << endl;
  return 0;
}
