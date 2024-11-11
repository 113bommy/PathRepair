#include <bits/stdc++.h>
using namespace std;
long long A[1000006], cum[1000006], B[1000006];
int main() {
  int l = 1, r = 2, st, en, n, k;
  long long sum = 0, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> A[i], B[i] = A[i];
  sort(A + 1, A + n + 1);
  cin >> k;
  std::map<int, int> mp;
  cum[0] = 0;
  for (int i = 1; i <= n; i++) cum[i] = cum[i - 1] + A[i];
  while (r <= k) {
    sum += (A[r] * (r - l) - (cum[r - 1] - cum[l - 1]));
    r++;
  }
  st = 1, en = k, ans = sum;
  while (r <= n) {
    sum -= (cum[r - 1] - cum[l] - A[l] * (r - l - 1));
    l++;
    sum += (A[r] * (r - l) - (cum[r - 1] - cum[l - 1]));
    if (ans > sum) {
      ans = sum;
      st = l;
      en = r;
    }
    r++;
  }
  for (int i = st; i <= en; ++i) {
    mp[A[i]] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    if (mp[B[i]] == 1) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}
