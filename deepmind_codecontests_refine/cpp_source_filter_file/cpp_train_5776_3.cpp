#include <bits/stdc++.h>
using namespace std;
int prefix_sum[500005];
int n;
int sp[500005];
int main() {
  string line;
  getline(cin, line);
  memset(prefix_sum, 0, sizeof prefix_sum);
  n = line.length();
  for (int i = 0; i < n; i++) {
    if (line[i] == 'I' || line[i] == 'E' || line[i] == 'A' || line[i] == 'O' ||
        line[i] == 'U' || line[i] == 'Y') {
      if (i == 0)
        prefix_sum[i] = 1;
      else
        prefix_sum[i] = prefix_sum[i - 1] + 1;
    } else {
      if (i > 0) prefix_sum[i] = prefix_sum[i - 1];
    }
  }
  double res = 0;
  sp[1] = prefix_sum[n - 1];
  res += sp[1] / 1.0;
  for (int i = 2; i <= n; i++) {
    if (i > n - i + 1) {
      sp[i] = sp[i - 1] - (prefix_sum[i - 2] - prefix_sum[n - i]);
    } else {
      sp[i] = sp[i - 1] + (prefix_sum[n - i] - prefix_sum[i - 2]);
    }
    res += sp[i] / (double)i;
  }
  printf("%.7f\n", res);
  return 0;
}
