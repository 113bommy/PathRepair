#include <bits/stdc++.h>
using namespace std;
int A[100006], B[100006], p[100006];
bool mark[100006];
int comp(int &a, int &b) {
  if (A[a] > A[b])
    return 1;
  else
    return 0;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> B[i];
    p[i] = i;
  }
  sort(p + 1, p + n + 1, comp);
  mark[1] = true;
  for (int i = 2; i <= n - 1; i += 2) {
    if (B[p[i]] > B[p[i + 1]])
      mark[i] = true;
    else
      mark[i + 1] = true;
  }
  if (!(n & 1)) {
    mark[n] = true;
    printf("%d\n", n / 2 + 1);
  } else
    printf("%d\n", n / 2 + 1);
  for (int i = 1; i <= n; i++) {
    if (mark[i]) printf("%d ", p[i]);
  }
  return 0;
}
