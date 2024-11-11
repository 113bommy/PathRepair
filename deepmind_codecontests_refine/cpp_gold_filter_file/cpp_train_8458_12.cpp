#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int p[100005], i, ans[100005];
    int num[100] = {0};
    for (i = 0; i < n * 2; i++) {
      cin >> p[i];
      num[p[i]]++;
    }
    int j = 0;
    for (i = 0; i < n * 2; i++) {
      if (num[p[i]] > 1) {
        ans[j] = p[i];
        j++;
        num[p[i]]--;
      }
    }
    for (i = 0; i < j; i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
