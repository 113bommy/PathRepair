#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
int a[maxn], b[maxn], n, pos[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    pos[b[i]] = i;
  }
  for (int i = 1; i < n; ++i) {
    if (pos[a[i - 1]] > pos[a[i]]) {
      cout << n - i;
      return 0;
    }
  }
  cout << n - 1 << endl;
  return 0;
}
