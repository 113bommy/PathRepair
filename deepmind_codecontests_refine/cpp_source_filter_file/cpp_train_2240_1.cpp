#include <bits/stdc++.h>
using namespace std;
int BIT1[1000010], BIT2[1000010], arr[1000010], val[1000010];
map<int, int> m;
int ans[1000010];
void pointupdate(int index, int val, int n, int BIT[]) {
  for (int i = index; i <= n; i += (i & (-i))) {
    BIT[i] += val;
  }
}
int getsum(int index, int n, int BIT[]) {
  int sum = 0;
  for (int i = index; i > 0; i -= (i & (-i))) {
    sum += BIT[i];
  }
  return sum;
}
int main() {
  int n;
  cin >> n;
  int k = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (!m[arr[i]]) {
      val[k++] = arr[i];
      m[arr[i]]++;
    }
  }
  sort(val, val + k);
  for (int i = 0; i < k; i++) {
    m[val[i]] = i + 1;
  }
  int k1 = 0;
  for (int i = 0; i < n; i++) {
    int x = m[arr[i]];
    if (x == k)
      ans[i] = 0;
    else {
      int sum1 = getsum(k, k, BIT1);
      int sum2 = getsum(x, k, BIT1);
      ans[i] = sum1 - sum2;
    }
    pointupdate(x, 1, n, BIT1);
  }
  long long ans1 = 0;
  for (int i = n - 1; i >= 0; i--) {
    int x = m[arr[i]];
    if (x > 1) {
      int sum1 = getsum(x - 1, k, BIT2);
      if (sum1) ans1 = ans1 + ans[i] * sum1;
    }
    pointupdate(x, 1, k, BIT2);
  }
  cout << ans1 << endl;
}
