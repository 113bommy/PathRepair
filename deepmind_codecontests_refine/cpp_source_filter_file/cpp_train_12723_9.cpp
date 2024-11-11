#include <bits/stdc++.h>
using namespace std;
map<int, int> v;
int main() {
  int n, a;
  scanf("%d", &n);
  int maxx = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    v[a]++;
    maxx = max(a, maxx);
  }
  if (n & 1 or v.size() == 1) {
    printf("NO\n");
    return 0;
  }
  bool first = true;
  bool flag = true;
  int k = v.begin()->first;
  while (1) {
    int cnt = v[k];
    if (first) {
      if (k + 1 == maxx) {
        flag = v[k + 1] == cnt;
        break;
      }
      if (cnt > v[k + 1] + 1) {
        flag = false;
        break;
      }
      v[k + 1] -= (cnt + 1);
      first = false;
    } else if (k + 1 < maxx) {
      if (cnt + 2 > v[k + 1]) {
        flag = false;
        break;
      }
      v[k + 1] -= cnt + 2;
    } else {
      flag = (cnt + 2 == v[k + 1] + 1);
      break;
    }
    k++;
  }
  printf("%s\n", (flag ? "YES" : "NO"));
  return 0;
}
