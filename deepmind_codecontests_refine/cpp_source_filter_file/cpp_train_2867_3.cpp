#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a, b, c, d;
  cin >> n >> k;
  cin >> a >> b >> c >> d;
  vector<int> path1(n + 1);
  path1[0] = a;
  path1[n - 1] = b;
  path1[1] = c;
  path1[n - 2] = d;
  int idx = 2;
  for (int i = 1; i <= n; i++) {
    if (i != a && i != b && i != c && i != d) {
      path1[idx] = i;
      idx++;
    }
  }
  vector<int> path2(n + 1);
  path2[0] = c;
  path2[n - 1] = d;
  path2[1] = a;
  path2[n - 2] = b;
  for (int i = 2; i <= n - 3; i++) {
    path2[i] = path1[i];
  }
  if (n != 4 && n + 1 > k)
    printf("-1\n");
  else {
    for (int i = 0; i < n; i++) cout << path1[i] << ' ';
    cout << endl;
    for (int i = 0; i < n; i++) cout << path2[i] << ' ';
    cout << endl;
  }
  return 0;
}
