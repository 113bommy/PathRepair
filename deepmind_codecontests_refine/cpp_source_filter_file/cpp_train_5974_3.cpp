#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a[100005];
bool tag[100005];
int main() {
  while (scanf("%d %d", &n, &k) != EOF) {
    for (int i = 0; i < n; i++) scanf("%I64d", a + i);
    memset(tag, false, sizeof(tag));
    sort(a, a + n);
    int ans = n;
    for (int i = 0; i < n; i++) {
      if (!tag[i]) {
        int p = a[i] * k;
        if (p > a[n - 1]) continue;
        int low = i + 1, high = n - 1, mid;
        while (low <= high) {
          mid = (low + high) / 2;
          if (a[mid] > p)
            high = mid - 1;
          else if (a[mid] < p)
            low = mid + 1;
          else {
            tag[mid] = true;
            ans--;
            break;
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
