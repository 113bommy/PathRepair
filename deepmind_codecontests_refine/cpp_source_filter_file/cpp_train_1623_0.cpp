#include <bits/stdc++.h>
int main() {
  char b[123];
  int n, k;
  scanf("%d%d%s", &n, &k, b);
  int c = 0, mx = 0;
  for (int i = 0; i < n; ++i) {
    if (b[i] == 'N')
      ++c;
    else {
      mx = c > mx ? mx : c;
      c = 0;
    }
  }
  mx = c > mx ? c : mx;
  if (mx > k) {
    puts("NO");
    return 0;
  }
  if (mx == k) {
    puts("YES");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    while (b[i] == 'Y') ++i;
    c = 0;
    if (i >= n) break;
    if (i > 0 && b[i - 1] == 'N') {
      while (b[i] == 'N') ++i;
      ++i;
    }
    if (i >= n) break;
    int j = i;
    while ((b[j] == 'N' || b[j] == '?') && c < k) {
      ++c;
      ++j;
    }
    if (c == k && (b[j] == '?' || b[j] == 'Y' || b[j] == '\0')) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
