#include <bits/stdc++.h>
using namespace std;
const int N = 200004;
int a[N];
int h[N];
vector<int> vec;
int main() {
  int n, s;
  scanf("%d %d", &n, &s);
  int i;
  int ans = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (i == s) {
      if (a[i] != 0) ans++;
      h[0]++;
      vec.push_back(0);
    } else {
      h[a[i]]++;
      vec.push_back(a[i]);
    }
  }
  sort(vec.begin(), vec.end());
  int id = vec.size() - 1;
  int cnt = h[0] - 1;
  i = 0;
  while (i <= a[id]) {
    if (h[i] == 0) {
      if (cnt > 0) {
        ans++;
        cnt--;
      } else {
        ans++;
        id--;
      }
    }
    i++;
  }
  ans += cnt;
  printf("%d\n", ans);
  return 0;
}
