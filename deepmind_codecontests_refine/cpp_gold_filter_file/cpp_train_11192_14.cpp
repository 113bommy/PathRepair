#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[1000007], b[1000007];
void mRead() {
  cin >> n >> m;
  int x;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) cin >> b[i];
}
long long mSolve() {
  mRead();
  sort(a, a + n);
  for (int i = 0; i < m; i++)
    cout << distance(a, upper_bound(a, a + n, b[i])) << " ";
  return 0;
}
int main() {
  mSolve();
  return 0;
}
