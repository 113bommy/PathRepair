#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e3;
bool flag[mxn + 11];
vector<int> v;
void init() {
  memset(flag, true, sizeof(flag));
  for (int i = 2; i <= mxn; i++) {
    if (flag[i]) {
      for (int j = i + i; j <= mxn; j += i) {
        flag[j] = false;
      }
    }
  }
  return;
}
int main() {
  init();
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    if (flag[i]) {
      for (int j = i; j <= n; j += i) {
        v.push_back(j);
      }
    }
  }
  printf("%d\n", v.size());
  for (int i = 0; i < v.size(); i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
  return 0;
}
