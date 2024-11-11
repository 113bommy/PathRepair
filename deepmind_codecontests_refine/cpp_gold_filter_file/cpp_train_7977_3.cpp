#include <bits/stdc++.h>
using namespace std;
int f[1010], n, a;
vector<int> ke[1010];
int main() {
  scanf("%d", &n);
  memset(f, 0, sizeof(f));
  for (int i = 2; i <= n; i++) {
    scanf("%d", &a);
    ke[a].push_back(i);
  };
  bool kq = true;
  for (int i = 1; i <= n; i++)
    if (ke[i].size()) {
      int dem = 0;
      for (int j = 0; j < ke[i].size(); j++)
        if (ke[ke[i][j]].empty()) dem++;
      if (dem < 3) {
        kq = false;
        break;
      };
    };
  if (kq)
    printf("Yes");
  else
    printf("No");
  return 0;
}
