#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, data;
  string temp, f;
  scanf("%d %d", &n, &m);
  int l = 0, r = n + 1;
  for (int i = 0; i < m; i++) {
    cin >> temp >> temp >> f >> temp >> data;
    if (f == "right")
      l = max(data, l);
    else if (f == "left")
      r = min(data, r);
  }
  if (r - l <= 1)
    printf("-1");
  else
    printf("%d", r - l - 1);
  return 0;
}
