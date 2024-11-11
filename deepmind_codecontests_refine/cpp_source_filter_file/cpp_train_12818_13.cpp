#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
string s;
int v[101];
int n, x, y;
int main() {
  cin >> n;
  cin >> x;
  cin >> y;
  int r = 0;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v, v + n);
  int i = 0;
  while (v[i] <= x) i++;
  double e = i / 2.0;
  e = ceil(e);
  r += (int)e;
  if (x <= y)
    printf("%d\n", r);
  else
    printf("%d\n", n);
  return 0;
}
