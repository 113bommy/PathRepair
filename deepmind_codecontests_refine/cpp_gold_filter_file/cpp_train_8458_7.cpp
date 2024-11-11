#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int t;
int n;
int a[101];
int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    bool f[51] = {};
    vector<int> ans;
    for (int i = 0; i < 2 * n; i++) {
      scanf("%d", a + i);
      if (!f[a[i]]) {
        ans.push_back(a[i]);
        f[a[i]] = 1;
      }
    }
    for (int v : ans) printf("%d ", v);
    printf("\n");
  }
}
