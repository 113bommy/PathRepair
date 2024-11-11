#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], b[N];
vector<int> vee[N];
int serch(int l, int r, int x) {
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (b[mid] >= x)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return l - 1;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    int pos = serch(0, n, a[i]);
    b[pos] = a[i];
    vee[pos].push_back(a[i]);
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < vee[i].size(); j++) {
      if (j == vee[i].size() - 1)
        printf("%d\n", vee[i][j]);
      else
        printf("%d ", vee[i][j]);
    }
  }
}
