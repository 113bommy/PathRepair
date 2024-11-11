#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
const int MAXVAL = 10000;
int a[MAXN + 1], cnt[10 * MAXVAL], calcBits[10 * MAXVAL], n, k;
int countBits(int x) {
  int res = 0;
  while (x > 0) {
    res += x % 2;
    x /= 2;
  }
  return res;
}
long long fastSol() {
  memset(cnt, 0, sizeof(cnt));
  memset(calcBits, 0, sizeof(calcBits));
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
  }
  for (int i = 0; i <= 5 * MAXVAL; i++) {
    calcBits[i] = countBits(i);
  }
  long long ans = 0;
  for (int i = 0; i <= MAXVAL; i++) {
    for (int j = 0; j <= MAXVAL; j++) {
      if (calcBits[i ^ j] == k) {
        if (i != j)
          ans += (long long)cnt[i] * cnt[j];
        else
          ans += (long long)cnt[j] * (cnt[j] - 1);
      }
    }
  }
  return ans / 2;
}
long long stupSol() {
  memset(calcBits, 0, sizeof(calcBits));
  for (int i = 0; i <= MAXVAL; i++) {
    calcBits[i] = countBits(i);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (calcBits[a[i] ^ a[j]] == k) {
        ans++;
      }
    }
  }
  return ans;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  cout << fastSol() << "\n";
  return 0;
}
