#include <bits/stdc++.h>
using namespace std;
long long n, m, A[30005], fix[300005], fix1[300005], B[300005], C[300005];
long long BITree[900005], BITree1[900005];
long long getSum(long long index) {
  long long sum = 0;
  index = index + 1;
  while (index > 0) {
    sum += BITree[index];
    index -= index & (-index);
  }
  return sum;
}
void updateBIT(long long index, long long val) {
  index = index + 1;
  while (index <= n + 10) {
    BITree[index] += val;
    index += index & (-index);
  }
}
long long getSum1(long long index) {
  long long sum = 0;
  index = index + 1;
  while (index > 0) {
    sum += BITree1[index];
    index -= index & (-index);
  }
  return sum;
}
void updateBIT1(long long index, long long val) {
  index = index + 1;
  while (index <= n + 10) {
    BITree1[index] += val;
    index += index & (-index);
  }
}
int main() {
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> A[i];
    if (fix[A[i]] == 0) updateBIT(A[i], 1);
    fix[A[i]] = 1;
    if (C[A[i]] != 0) {
      C[A[i]] = max(C[A[i]], A[i] - fix1[A[i]] - 1 + 1);
      C[A[i]] = max(C[A[i]], getSum1(i - 1) - getSum1(fix1[A[i]]) + 1);
      updateBIT1(fix1[A[i]], -1);
      updateBIT1(i, 1);
    } else {
      C[A[i]] = A[i] + getSum(n) - getSum(A[i]);
      updateBIT1(i, 1);
    }
    fix1[A[i]] = i;
  }
  for (long long i = n; i >= 1; i--) {
    B[i] = B[i + 1] + fix[i];
  }
  for (long long i = 1; i <= n; i++) {
    if (fix[i] == 0) {
      cout << i << " " << i + B[i];
    } else {
      cout << 1 << " " << max(C[i], getSum1(m) - getSum1(fix1[i]) + 1);
    }
    cout << endl;
  }
}
