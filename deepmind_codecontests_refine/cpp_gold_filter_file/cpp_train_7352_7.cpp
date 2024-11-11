#include <bits/stdc++.h>
using namespace std;
long long arr[2000005];
bool vis[2000005];
int main() {
  int n;
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", arr + i);
  }
  int st = n, en = n;
  for (int i = n; i >= 1; i--) {
    int from = (i - 1), to = i - arr[i];
    if (from < st) {
      cnt++;
    }
    if (to <= st) st = to - 1;
  }
  printf("%d", cnt);
}
