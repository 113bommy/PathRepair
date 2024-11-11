#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
int a[maxn];
int cnt[maxn];
int main() {
  long long sum = 0, ans = 0;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  long long l = 0, r = 0;
  for (int i = 1; i <= n; i++) {
    sum += abs(a[i] - i);
    if (a[i] >= i) {
      cnt[a[i] - i]++;
      l++;
    } else {
      r++;
    }
  }
  int id = 0;
  long long Min = sum;
  for (int i = 1; i <= n; i++) {
    r += cnt[i - 1];
    l -= cnt[i - 1];
    sum += (r - l) - 1;
    sum = sum - (n - a[n - i + 1]) + (a[n - i + 1] - 1);
    r--;
    l++;
    cnt[i + (a[n - i + 1] - 1)]++;
    if (sum < Min) {
      Min = sum;
      id = i;
    }
  }
  printf("%lld %d\n", Min, id);
  return 0;
}
