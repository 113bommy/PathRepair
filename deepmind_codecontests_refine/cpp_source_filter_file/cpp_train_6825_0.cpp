#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, k, a[N], ans = 0;
multiset<int> ms;
int main(int argc, char const *argv[]) {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (!a[i] && i != k) a[i] = n + 1;
    if (a[i] == k && a[i]) a[i] = 0, ans = 1;
    ms.insert(a[i]);
  }
  int mex = 0;
  while (!ms.empty()) {
    if (ms.find(mex) == ms.end()) {
      int k = *ms.rbegin();
      ms.erase(ms.find(k));
      ans++;
    } else {
      ms.erase(mex);
    }
    mex++;
  }
  cout << ans << '\n';
  return 0;
}
