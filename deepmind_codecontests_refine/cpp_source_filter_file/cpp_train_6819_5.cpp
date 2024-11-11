#include <bits/stdc++.h>
using namespace std;
int a[100000 + 1];
int A[100000 + 1] = {0};
int main() {
  int n;
  cin >> n;
  int m = n / 2 + n % 2;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++)
    if (a[i] - i > 0) A[a[i] - i]++;
  for (int i = m; i < n; i++)
    if (a[i] + i - n + 1 > 0) A[a[i] + i - n + 1]++;
  int M = 1, Mi = 0;
  for (int i = 1; i < 100000 + 1; i++)
    if (A[i] > M) M = A[i], Mi = i;
  int res = 0;
  for (int i = 0; i < m; i++)
    if (a[i] != Mi + i) res++;
  for (int i = m; i < n; i++)
    if (a[i] != Mi - (i - n + 1)) res++;
  cout << res;
  return 0;
}
