#include <bits/stdc++.h>
using namespace std;
int n;
int freq[1000005];
int main() {
  int x;
  scanf("%d %d", &n, &x);
  long long res = 0;
  for (int i = 0; i < n; i++) {
    int cur;
    scanf("%d", &cur);
    res += freq[x ^ cur];
    freq[cur]++;
  }
  printf("%lld", res);
  return 0;
}
