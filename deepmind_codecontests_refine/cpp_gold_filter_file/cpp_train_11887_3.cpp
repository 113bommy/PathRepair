#include <bits/stdc++.h>
using namespace std;
int a[200005], b[200005];
int main() {
  int n;
  cin >> n;
  n *= 2;
  long long sum = 1ll * (n + 1) * n / 2 * (n / 2);
  long long num = n / 2;
  if (sum % num == 0 && ((sum / num) & 1)) {
    long long k = sum / num;
    int l, r, no;
    l = 1, r = n / 2, no = 1;
    while (l <= r) {
      if (l != r) {
        a[l] = 2 * no - 1;
        no++;
        a[r] = 2 * no - 1;
        no++;
        l++;
        r--;
      } else {
        a[l] = 2 * no - 1;
        no++;
        l++;
        r--;
      }
    }
    l = 1, r = n / 2, no = n / 2;
    while (l <= r) {
      if (l != r) {
        b[r] = 2 * no;
        no--;
        b[l] = 2 * no;
        no--;
        l++;
        r--;
      } else {
        b[l] = 2 * no;
        no--;
        l++;
        r--;
      }
    }
    puts("YES");
    for (int i = 1; i <= n; i++) {
      if (i & 1) {
        printf("%d ", a[(i + 1) / 2]);
      } else {
        printf("%d ", b[i / 2]);
      }
    }
  } else {
    puts("NO");
  }
}
