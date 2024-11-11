#include <bits/stdc++.h>
using namespace std;
int intcmp(const void *v1, const void *v2) { return *(int *)v1 - *(int *)v2; }
set<int> ansSet;
int ans[100010];
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    ansSet.insert(a % k);
  }
  ans[0] = 1;
  int gcdres = k;
  for (auto v : ansSet) {
    if (v == 0) {
      continue;
    }
    gcdres = gcd(gcdres, v);
  }
  int cnt = k / gcdres;
  cout << cnt << endl;
  for (int i = 0; i < k; i += gcdres) {
    printf("%d ", i);
  }
  printf("\n");
  return 0;
}
