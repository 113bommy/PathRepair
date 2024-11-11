#include <bits/stdc++.h>
using namespace std;
void IO() {}
int ar[1005], pos[1005];
char ch[1005];
int m, n, k, ii;
void solve() {
  vector<int> v;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ar[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &pos[i]);
    if (pos[i] == 0) {
      v.push_back(ar[i]);
    }
  }
  sort(v.begin(), v.end());
  for (int i = 1; i <= n; i++) {
    if (pos[i] == 1)
      printf("%d ", ar[i]);
    else {
      printf("%d ", v.back());
      v.pop_back();
    }
  }
  printf("\n");
}
int main() {
  IO();
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
