#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, k;
int ans = 1 << 20, a[105], b[105];
vector<int> ret;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) cin >> a[i];
  for (int i = 0; i < k; i++) cin >> b[i];
  for (int i = 0; i < m; i++) {
    int cur = 0;
    for (int j = 0; j < k; j++)
      if (b[j] % a[i] == 0) cur++;
    if (cur == ans)
      ret.push_back(1 + i);
    else if (cur < ans) {
      ans = cur;
      ret.clear();
      ret.push_back(i + 1);
    }
  }
  cout << ret.size() << endl;
  for (int i = 0; i < ret.size(); i++) cout << ret[i] << " ";
  return 0;
}
