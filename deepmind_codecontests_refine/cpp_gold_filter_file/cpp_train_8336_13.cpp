#include <bits/stdc++.h>
using namespace std;
int n;
int pre[120005];
map<int, int> ma;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &pre[i]);
    ma[pre[i]]++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    bool flag = false;
    ma[pre[i]]--;
    for (int j = 0; j <= 30; j++) {
      int x = (1 << j);
      if (ma[x - pre[i]] != 0) {
        flag = true;
        break;
      }
    }
    ma[pre[i]]++;
    if (flag == false) ans++;
  }
  cout << ans << endl;
  return 0;
}
