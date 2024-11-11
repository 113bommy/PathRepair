#include <bits/stdc++.h>
using namespace std;
int n, mx[200006], dp[200005], ar[200005], b[200005];
vector<int> v;
int main() {
  scanf("%d", &n);
  for (int i = 3; i <= n; i++) {
    mx[i] = INT_MAX;
    int x = sqrt(i);
    ar[0] = 0;
    for (int j = 1; j <= x; j++) {
      ar[j] = 0;
      if (i % j == 0) {
        int k = i / j;
        if (j % 2) v.push_back(j);
        if (k != j && k % 2) v.push_back(k);
      }
    }
    for (int j = 0; j < v.size(); j++) {
      long long q = ((long long)v[j]) * (v[j] - 1);
      q /= 2;
      q = i - q;
      q /= v[j];
      if (q > 0 && q + v[j] - 1 <= i && v[j] > 1) {
        int r = b[q + v[j] - 1] ^ b[q - 1];
        if (r == 0) {
          mx[i] = min(mx[i], v[j]);
        }
        ar[r]++;
      }
      q = i / v[j];
      q += q;
      long long w = q;
      q = q * (q - 1);
      q /= 2;
      q = i - q;
      q /= w;
      if (q > 0 && q + w - 1 <= i) {
        int r = b[q + w - 1] ^ b[q - 1];
        if (r == 0) {
          mx[i] = min(mx[i], (int)w);
        }
        ar[r]++;
      }
    }
    for (int j = 0; j <= x + 1; j++) {
      if (ar[j] == 0) {
        dp[i] = j;
        break;
      }
    }
    b[i] = b[i - 1] ^ dp[i];
    v.clear();
  }
  if (dp[n] == 0) {
    printf("-1");
  } else {
    printf("%d\n", mx[n]);
  }
}
