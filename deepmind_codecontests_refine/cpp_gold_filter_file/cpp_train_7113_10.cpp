#include <bits/stdc++.h>
using namespace std;
long long ans, v;
int n, r = INT_MAX, k;
int main(int argc, char** argv) {
  scanf("%d%d", &n, &k);
  int s = 1, e = n;
  while (s <= e) {
    int mid = (s + e) / 2;
    ans = 0, v = 1;
    while (mid / v) {
      ans += mid / v;
      v *= k;
    }
    if (ans < n)
      s = mid + 1;
    else {
      e = mid - 1;
      r = min(r, mid);
    }
  }
  printf("%d", r);
  return 0;
}
