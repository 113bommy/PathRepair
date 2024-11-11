#include <bits/stdc++.h>
using namespace std;
vector<int> ans[1000];
int main() {
  int mark[1000];
  int n, k;
  scanf("%d %d", &n, &k);
  memset(mark, 0, sizeof(mark));
  for (int i = 1; i <= k; i++) {
    int val;
    scanf("%d", &val);
    ans[i].push_back(val);
    mark[val] = 1;
  }
  int count = 1;
  for (int i = 1; i <= n * k; i++) {
    while (ans[count].size() < n) {
      if (!mark[i]) ans[count].push_back(i);
      i++;
    }
    count++;
    i--;
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      printf("%d ", ans[i][j]);
    }
    cout << endl;
  }
  return 0;
}
