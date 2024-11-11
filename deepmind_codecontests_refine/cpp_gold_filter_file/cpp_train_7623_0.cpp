#include <bits/stdc++.h>
using namespace std;
int dfs(int i, int status[], list<int> l[], int n, int &collision, int &flag,
        int curr) {
  status[i] = 1;
  int ctr = 0;
  if (curr < 2) {
    ctr++;
  }
  int check = 1;
  for (auto it = l[i].begin(); it != l[i].end(); it++) {
    int j = *it;
    if (status[j] == 0) {
      int val = dfs(j, status, l, n, collision, flag, curr + 1);
      check += val;
      if (val < 2) {
        ctr++;
        if (ctr >= 2) {
          collision++;
        }
      }
    }
  }
  if (check == 1) {
    if (curr % 2 == 1) {
      flag = 1;
    }
  }
  return check;
}
int main() {
  int n;
  scanf("%d", &n);
  list<int> l[n + 1];
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    l[x].push_back(y);
    l[y].push_back(x);
  }
  int leaf = -1;
  for (int i = 1; i <= n; i++) {
    if (l[i].size() == 1) {
      leaf = i;
      break;
    }
  }
  int status[400001] = {0};
  int collision = 0, flag = 0;
  dfs(leaf, status, l, n, collision, flag, 0);
  int one = 1, two = n - 1;
  if (flag == 1) {
    one = 3;
  }
  cout << one << " " << two - collision << endl;
}
