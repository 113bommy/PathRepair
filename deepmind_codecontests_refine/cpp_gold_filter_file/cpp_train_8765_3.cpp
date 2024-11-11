#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int B = 300;
char s[MAXN];
int b[MAXN], c[MAXN * B];
int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  vector<int> ind;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    b[i] = b[i - 1] + s[i] - '0';
    if (s[i] == '1') ind.push_back(i);
  }
  ind.push_back(n + 1);
  for (int k = 1; k <= B - 1; k++) {
    for (int i = 0; i <= n; i++) ans += (long long)c[k * b[i] - i + n]++;
    for (int i = 0; i <= n; i++) c[k * b[i] - i + n]--;
  }
  for (int k = 1; k <= n / B; k++) {
    int j = k - 1;
    for (int i = 0; i <= n - 1 && j + 1 < ind.size(); i++) {
      ans +=
          (long long)max(0, (ind[j + 1] - 1 + k - i % k) / k -
                                (max(B * k + i, ind[j]) - 1 + k - i % k) / k);
      j += s[i + 1] == '1';
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
