#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
map<long long, int> m;
int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  int x;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    sum += x;
    ans = max(ans, ++m[sum]);
  }
  printf("%d\n", n - ans);
  return 0;
}
