#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int w[502] = {}, b[10002] = {};
  for (int i = 0; i < n; i++) cin >> w[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  int count[1000] = {};
  vector<int> ans;
  for (int i = 0; i < m; i++) {
    if (count[b[i]] == 0) {
      count[b[i]] = 1;
      ans.push_back(b[i]);
    }
  }
  long long int final = 0;
  for (int i = 1; i < m; i++) {
    int check[505] = {};
    for (int j = i - 1; j >= 0; j--) {
      if (b[j] == b[i]) break;
      if (check[b[j]] == 0) {
        check[b[j]] = 1;
        final += b[j];
      }
    }
  }
  cout << final << endl;
  return 0;
}
