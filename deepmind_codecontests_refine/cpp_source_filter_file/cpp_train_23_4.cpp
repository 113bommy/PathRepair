#include <bits/stdc++.h>
using namespace std;
int A[1000000], B[1000000], C[1000000];
int main() {
  int n, k, t, a, b;
  cin >> n >> k;
  int num1 = 0, num2 = 0, num3 = 0;
  for (int i = 1; i <= n; i++) {
    cin >> t >> a >> b;
    if (a == 1 && b != 1) A[++num1] = t;
    if (a == 0 && b == 1) B[++num2] = t;
    if (a == 1 && b == 1) C[++num3] = t;
  }
  if (num1 + num3 < k || num2 + num3 < k) {
    cout << -1;
    return 0;
  }
  sort(A + 1, A + num1 + 1);
  sort(B + 1, B + num2 + 1);
  sort(C + 1, C + num3 + 1);
  int i = 1, j = 1;
  int num = 0;
  int sum = 0;
  while (num < k) {
    if ((i > num1 && num1 < k) || (i > num2 && num2 < k)) {
      sum += C[j];
      j++;
      num++;
      continue;
    }
    if (A[i] + B[i] <= C[j] || j >= num3) {
      sum += (A[i] + B[i]);
      i++;
    } else {
      sum += C[j];
      j++;
    }
    num++;
  }
  cout << sum << endl;
  return 0;
}
