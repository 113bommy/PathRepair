#include <bits/stdc++.h>
using namespace std;
long long n, x[100005], b[100005], c[100005];
long long maxSubArraySum(long long a[], int size) {
  long long solution[size + 1];
  solution[0] = 0;
  for (int j = 1; j < size + 1; j++) {
    solution[j] = max(solution[j - 1] + a[j - 1], a[j - 1]);
  }
  long long result = solution[0];
  for (int j = 1; j < size + 1; j++) {
    if (result < solution[j]) result = solution[j];
  }
  return result;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int i = 1; i < n; i++) {
    b[i - 1] = abs(x[i] - x[i + 1]);
    if (i % 2 == 0) b[i - 1] *= (-1);
  }
  for (int i = 1; i < n; i++) {
    c[i - 1] = abs(x[i] - x[i + 1]);
    if (i % 2 == 1) c[i - 1] *= (-1);
  }
  long long x = maxSubArraySum(b, n - 1);
  long long y = maxSubArraySum(c, n - 1);
  cout << max(x, y);
  return 0;
}
