#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, t;
  int *m = new int[100001];
  int *m1 = new int[100001];
  int *m2 = new int[100001];
  cin >> n >> t;
  for (int i = 0; i < n; ++i) cin >> m[i];
  m1[n - 1] = 1;
  m2[0] = 1;
  for (int i = 1; i < n; ++i)
    if (m[i] <= m[i - 1])
      m2[i] = m2[i - 1] + 1;
    else
      m2[i] = 1;
  for (int i = n - 2; i >= 0; --i)
    if (m[i] <= m[i + 1])
      m1[i] = m1[i + 1] + 1;
    else
      m1[i] = 1;
  int a, b;
  for (int i = 0; i < t; ++i) {
    cin >> a >> b;
    --a;
    --b;
    if (m2[b] + m1[a] >= b - a + 2)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}
