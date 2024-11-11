#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, *a, *b, *p, sum = 0, ans = 0;
  vector<int> c;
  cin >> n;
  a = (int*)malloc(sizeof(int) * n);
  b = (int*)malloc(sizeof(int) * n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  p = &b[0];
  c.push_back(0);
  for (int i = 1; i < n; ++i) {
    if (*p > b[i]) {
      c.push_back(i);
      p = &b[i];
    }
  }
  c.push_back(n);
  for (size_t i = 0; i < c.size() - 1; ++i) {
    for (int j = c[i]; j < c[i + 1]; ++j) sum += a[j];
    ans += sum * b[c[i]];
    sum = 0;
  }
  cout << ans << endl;
  free(a);
  free(b);
  c.clear();
  return 0;
}
