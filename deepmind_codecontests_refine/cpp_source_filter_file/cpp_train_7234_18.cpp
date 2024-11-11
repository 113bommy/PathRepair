#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int siz = 100005;
int cum1[siz], cum2[siz];
int main() {
  int n;
  cin >> n;
  int res = 0;
  vector<int> v(n + 2, 0);
  for (int i = (1); i < (n + 1); i++) cin >> v[i];
  int j = n;
  for (int i = (1); i < (n + 1); i++) {
    cum1[i] = min(cum1[i - 1] + 1, v[i]);
    cum2[j] = min(cum2[j + 1] + 1, v[i]);
    j--;
  }
  for (int i = (1); i < (n + 1); i++) res = max(res, min(cum1[i], cum2[i]));
  cout << res << endl;
  return 0;
}
