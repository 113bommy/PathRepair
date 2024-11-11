#include <bits/stdc++.h>
using namespace std;
long long a[100010];
long long sum[100010];
int n;
long long k;
struct node {
  long long x;
  long long y;
};
long long gcd(long long a, long long b) {
  return b == 0 ? a : a > b ? gcd(b, a % b) : gcd(a, b % a);
}
bool myfunc(struct node a, struct node b) {
  if (a.x == b.x) {
    return a.y < b.y;
  } else {
    return a.x < b.x;
  }
}
long long bsearch(int i) {
  int j = i;
  int l = 1;
  while (l < j) {
    int mid = (l + j) / 2;
    long long z = (i - mid) * a[i] - (sum[i - 1] - sum[mid - 1]);
    if (z <= k) {
      j = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  long long z = (i - l) * a[i] - sum[i - 1] + sum[l - 1];
  if (z <= k) {
    return (i - l + 1);
  } else {
    return i - l;
  }
}
int main() {
  cin >> n >> k;
  int i;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  sum[0] = 0;
  sum[1] = a[1];
  for (i = 2; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  long long ans = 1;
  long long g = a[1];
  for (i = 2; i <= n; i++) {
    long long an = bsearch(i);
    if (an != -1) {
      if (an > ans) {
        ans = an;
        g = a[i];
      }
    }
  }
  cout << ans << " " << g << endl;
  return 0;
}
