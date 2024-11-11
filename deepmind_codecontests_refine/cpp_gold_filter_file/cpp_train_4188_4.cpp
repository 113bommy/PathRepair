#include <bits/stdc++.h>
using namespace std;
long long a[100000], b;
int n;
long long maxSubArraySum() {
  long long max_so_far = 0, max_ending_here = 0, max_so_far_2 = 0,
            max_ending_here_2 = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      max_ending_here += a[i];
      if (max_ending_here < 0)
        max_ending_here = 0;
      else if (max_so_far < max_ending_here)
        max_so_far = max_ending_here;
    }
    if (i < n - 1) {
      max_ending_here_2 += a[i];
      if (max_ending_here_2 < 0)
        max_ending_here_2 = 0;
      else if (max_so_far_2 < max_ending_here_2)
        max_so_far_2 = max_ending_here_2;
    }
  }
  return max(max_so_far, max_so_far_2);
}
int main() {
  int t;
  scanf("%d", &t);
  for (; t--;) {
    scanf("%d", &n);
    b = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
      b += a[i];
    }
    if (maxSubArraySum() < b)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
