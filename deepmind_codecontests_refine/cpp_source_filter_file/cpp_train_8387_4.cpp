#include <bits/stdc++.h>
using namespace std;
vector<int> arr[1000000];
int t[1000000];
int sum = 0;
int f = -1, s = -1;
int dfs(int v, int p) {
  int su = t[v];
  for (int to : arr[v]) {
    if (to != p) {
      su += dfs(to, v);
    }
  }
  if (su == sum) {
    if (p != -1) {
      if (f == -1) {
        f = v + 1;
      } else if (s == -1) {
        s = v + 1;
      }
    }
    su = 0;
  }
  return su;
}
int main() {
  int n;
  scanf("%d", &n);
  int sqrt = -1;
  for (int i = 0; i < n; i++) {
    int p;
    scanf("%d%d", &p, &t[i]);
    sum += t[i];
    if (p > 0) {
      arr[i].push_back(p - 1);
      arr[p - 1].push_back(i);
    } else
      sqrt = i;
  }
  if (sum % 3 > 0) {
    printf("%d", -1);
    return 0;
  }
  sum /= 3;
  dfs(sqrt, -1);
  if (s == -1) {
    printf("%d", -1);
  } else {
    printf("%d %d", f, s);
  }
  return 0;
}
