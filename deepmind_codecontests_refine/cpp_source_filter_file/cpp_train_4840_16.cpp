#include <bits/stdc++.h>
using namespace std;
inline int gn(char x) { return x - '0'; }
vector<int> ans;
int main() {
  int n;
  scanf("%d\n", &n);
  for (int i = 1; i <= n; i++) {
    int toadd = 1;
    for (int j = 1; j <= n; j++) {
      char x;
      scanf("%c", &x);
      if (x == '1' || x == '3') toadd = 0;
    }
    if (toadd) ans.push_back(i);
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
