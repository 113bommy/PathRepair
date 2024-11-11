#include <bits/stdc++.h>
using namespace std;
bool a[1000005];
int ans[1000005];
int main() {
  queue<int> v;
  memset(a, true, sizeof(a));
  a[0] = a[1] = 0;
  for (long long i = 2; i <= 1000000; i++) {
    if (a[i]) {
      for (long long j = i * i; j <= 1000000; j += i) a[j] = 0;
      v.push(i);
    }
    int y = (sqrt(i));
    while (!v.empty() && v.front() <= (y)) v.pop();
    ans[i] = v.size();
  }
  int tests;
  scanf("%d", &tests);
  while (tests--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", ans[x] + 1);
  }
}
