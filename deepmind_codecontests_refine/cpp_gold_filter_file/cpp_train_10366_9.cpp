#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 1123;
int ans[MAX];
int main() {
  int n;
  cin >> n;
  memset(ans, INF, sizeof(ans));
  for (int i = 0; i < 10; i++) {
    vector<int> data1, data2;
    for (int j = 1; j <= n; j++) {
      if (j & (1 << i))
        data1.push_back(j);
      else
        data2.push_back(j);
    }
    if (data1.size()) {
      cout << data1.size() << endl;
      for (int j = 0; j < data1.size(); j++) {
        cout << data1[j] << " ";
      }
      for (int j = 1; j <= n; j++) {
        int t;
        cin >> t;
        if ((j & (1 << i)) == 0) {
          ans[j] = min(ans[j], t);
        }
      }
      cout << endl;
      fflush(stdout);
    }
    if (data2.size()) {
      cout << data2.size() << endl;
      for (int j = 0; j < data2.size(); j++) {
        cout << data2[j] << " ";
      }
      for (int j = 1; j <= n; j++) {
        int t;
        cin >> t;
        if (j & (1 << i)) ans[j] = min(ans[j], t);
      }
      cout << endl;
      fflush(stdout);
    }
  }
  fflush(stdout);
  cout << -1 << endl;
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
