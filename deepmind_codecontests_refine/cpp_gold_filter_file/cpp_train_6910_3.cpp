#include <bits/stdc++.h>
using namespace std;
int arr[2 * 100005], in, n, info[2 * 100005];
double sum;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tp, a, x, k;
    cin >> tp;
    if (tp == 1) {
      cin >> a >> x;
      arr[a - 1] += x;
      info[a - 1] = info[a - 1] + x;
      sum = sum + ((long long)x) * a;
      printf("%.8lf\n", sum / (in + 1));
    } else if (tp == 2) {
      cin >> k;
      sum = sum + k;
      arr[++in] = k;
      printf("%.8lf\n", sum / (in + 1));
    } else {
      sum = sum - arr[in];
      arr[in - 1] = arr[in - 1] + info[in];
      info[in - 1] += info[in];
      arr[in] = info[in] = 0;
      in--;
      printf("%.8lf\n", sum / (in + 1));
    }
  }
  return 0;
}
