#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int data[N][2];
vector<int> p_son[N];
vector<int> res;
int mark[N];
int key = 0, n;
int dfs(int par);
int main() {
  scanf("%d", &n);
  memset(mark, 0, sizeof(mark));
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &data[i][0], &data[i][1]);
    mark[data[i][0]]++;
    p_son[data[i][0]].push_back(i);
    sum += data[i][1];
  }
  if (sum % 3 == 0 && sum != 0) {
    key = sum / 3;
    dfs(0);
    if (res.size() >= 2) {
      for (int i = 0; i < 2; i++) {
        printf("%d ", res[i]);
      }
      printf("\n");
    } else {
      printf("-1\n");
    }
  } else {
    printf("-1\n");
  }
  return 0;
}
int dfs(int par) {
  int sum = data[par][1];
  for (int i = 0; i < p_son[par].size(); i++) {
    sum += dfs(p_son[par][i]);
  }
  if (sum == key) {
    res.push_back(par);
    return 0;
  }
  return sum;
}
