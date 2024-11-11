#include <bits/stdc++.h>
using namespace std;
map<long long, int> q;
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int i;
    long long sum = 0;
    int ans = 0;
    for (i = 0; i < n; i++) {
      int a;
      cin >> a;
      sum += (long long)a;
      q[sum]++;
      ans = max(ans, q[sum]);
    }
    printf("%d\n", n - ans);
  }
  return 0;
}
