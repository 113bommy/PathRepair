#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int mark[maxn + 10], a[maxn + 10];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], mark[a[i]]++;
  for (int i = 2; i <= maxn; i++)
    if (mark[i] > mark[i - 1]) {
      cout << -1 << endl;
      return 0;
    }
  cout << mark[a[1]] << endl;
  memset(mark, false, sizeof mark);
  for (int i = 1; i <= n; i++) {
    mark[a[i]]++;
    cout << mark[a[i]] << " ";
  }
  return 0;
}
