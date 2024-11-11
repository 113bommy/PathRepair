#include <bits/stdc++.h>
using namespace std;
long long bit[4][1000006] = {0};
long long a[1000006], temp[1000006];
long long n, k;
void convert() {
  for (int i = 0; i < n; i++) {
    temp[i] = a[i];
  }
  sort(temp, temp + n);
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(temp, temp + n, a[i]) - temp + 1;
  }
}
void add(int t, int i, long long val) {
  for (; i <= n; i = i + (i & (-i))) {
    bit[t][i] = bit[t][i] + val;
  }
}
int sum(int t, int i) {
  long long res = 0;
  for (; i > 0; i = i - (i & (-i))) {
    res = res + bit[t][i];
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  k = 3;
  long long i, l, x;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  convert();
  for (i = n - 1; i >= 0; i--) {
    x = a[i];
    add(1, x, 1LL);
    for (l = 1; l < k; l++) {
      add(l + 1, x, sum(l, x - 1));
    }
  }
  cout << sum(k, n);
  return 0;
}
