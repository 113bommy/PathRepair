#include <bits/stdc++.h>
using namespace std;
int n, m, ans, a[10010];
bool b[10010];
vector<int> p[10010];
int main(int argc, const char* argv[]) {
  int i, j, k;
  cin >> n;
  for (i = 1; i <= n; ++i) {
    cin >> a[i];
    p[a[i]].push_back(i);
  }
  ans = 0;
  int tot = 0;
  for (i = 1; i <= n; ++i)
    if (a[i] == i)
      ans++;
    else if (p[i].size() > 0)
      tot++;
  cout << ans + (tot / 2) << endl;
  return 0;
}
