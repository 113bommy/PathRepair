#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
long long int sum[maxn + 1];
long long int a[maxn], b[maxn];
void add(int i, long long int k) {
  for (; i <= maxn; i += i & -i) {
    sum[i] += k;
  }
}
long long int get(int i) {
  long long int ret = 0;
  for (; i; i -= i & -i) {
    ret += sum[i];
  }
  return ret;
}
int main() {
  int n, k;
  cin >> n >> k;
  k = k + 1;
  for (int i = 0; i < n; i++) cin >> a[i], a[i]++, b[i] = 1;
  for (int i = 0; i < k; i++) {
    memset(sum, 0, sizeof(sum));
    for (int j = 0; j < n; j++) {
      add(a[j], b[j]);
      b[j] = get(a[j] - 1);
    }
  }
  cout << get(maxn) << "\n";
  return 0;
}
