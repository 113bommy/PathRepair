#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  register unsigned int i, j;
  unsigned int n, m;
  cin >> n >> m;
  double x;
  std::vector<double> l;
  std::vector<double> t;
  char flag = 'p';
  for (i = 0; i < n; ++i) {
    cin >> x;
    if (x <= 1) flag = 'f';
    t.push_back(x);
  }
  for (i = 0; i < n; ++i) {
    cin >> x;
    if (x <= 1) flag = 'f';
    l.push_back(x);
  }
  if (flag == 'f')
    cout << "-1";
  else {
    x = double(m);
    x += x / (l[0] - 1);
    for (i = 1; i < n; i++) {
      x += x / (t[i] - 1);
      x += x / (l[i] - 1);
    }
    x += x / (t[0] - 1);
    printf("%.6lf", x - m);
  }
  return (0);
}
