#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;
int a[N], n, m, f[N], p[N];
bool v[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if (a[i] <= m) f[a[i]]++;
    if (a[i] <= m) v[a[i]] = 1;
  }
  int mxp = 1, mx = 0;
  for (int i = 1; i <= m; i++) {
    if (v[i]) {
      for (int j = i; j <= m; j += i) {
        p[j] += f[i];
      }
    }
    if (p[i] > mx) {
      mx = p[i];
      mxp = i;
    }
  }
  cout << mxp;
  vector<int> a2;
  for (int i = 0; i < n; i++) {
    if (mxp % a[i] == 0) a2.push_back(i + 1);
  }
  cout << " " << a2.size() << endl;
  for (int i = 0; i < a2.size(); i++) cout << a2[i] << " ";
  return 0;
}
