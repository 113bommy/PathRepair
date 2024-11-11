#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int k;
int sum;
map<int, pair<int, int> > m;
int a[MAXN];
int n;
bool flag;
int main() {
  cin >> k;
  int i;
  flag = 0;
  for (i = 1; i <= k; i++) {
    sum = 0;
    cin >> n;
    int j;
    for (j = 1; j <= n; j++) {
      cin >> a[j];
      sum += a[j];
    }
    for (j = 1; j <= n; j++) {
      if (m.count(sum - a[j])) {
        flag = 1;
        cout << "Yes" << endl;
        cout << m[sum - a[j]].first << " " << m[sum - a[j]].second << endl;
        cout << i << " " << j << endl;
        break;
      }
    }
    if (flag) break;
    for (j = 1; j <= n; j++) {
      m[sum - a[j]] = make_pair(i, j);
    }
  }
  if (!flag) cout << "No" << endl;
  return 0;
}
