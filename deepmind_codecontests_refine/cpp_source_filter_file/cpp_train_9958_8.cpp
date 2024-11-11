#include <bits/stdc++.h>
using namespace std;
int a, b, c, A[100005], B[100005], n, m, nr;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> B[i];
  }
  int st = 1, dr = 1, s1 = 0, s2 = 0;
  while (st <= n && dr <= m) {
    if (s1 == 0) s1 += A[st++];
    if (s2 == 0) s2 += B[dr++];
    if (s1 < s2)
      s1 += A[st++];
    else if (s2 < s1)
      s2 += B[dr++];
    else {
      s1 = s2 = 0;
      nr++;
    }
  }
  if (st != 0 || dr != 0) nr++;
  cout << nr;
  return 0;
}
