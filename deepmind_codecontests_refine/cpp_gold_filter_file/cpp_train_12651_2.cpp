#include <bits/stdc++.h>
using namespace std;
int v[1000005];
int main() {
  int n;
  cin >> n;
  for (int i = int(0); i < int(1000005); i++) v[i] = 0;
  int ans = -1;
  int max = 0;
  for (int i = int(0); i < int(n); i++) {
    int x;
    scanf("%d", &x);
    v[x]++;
    if (v[x] > max) {
      max = v[x];
      ans = x;
    }
  }
  printf("%d\n", ans);
  return 0;
}
