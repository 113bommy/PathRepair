#include <bits/stdc++.h>
using namespace std;
int t[100005];
int main(int argc, const char* argv[]) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &t[i]);
  sort(t, t + n);
  int ans = 0, s = 0;
  for (int i = 0; i < n; ++i) {
    if (s < t[i]) {
      ++ans;
      s += t[i];
    }
  }
  printf("%d", ans);
  return 0;
}
