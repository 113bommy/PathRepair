#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
long long x[N], y[N];
long long getArea(int a, int b, int c) {
  return abs((x[b] - x[a]) * (y[c] - y[a]) - (x[c] - x[a]) * (y[b] - y[a]));
}
long long n, s, a, b, c;
int main() {
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  a = 1, b = 2, c = 3;
  long long S = getArea(a, b, c);
  while (1) {
    int flag = 0;
    for (int i = 1; i <= n; i++) {
      S = getArea(a, b, c);
      if (S < getArea(i, b, c))
        a = i, flag = 1;
      else if (S < getArea(a, i, c))
        b = i, flag = 1;
      else if (S < getArea(a, b, i))
        c = i, flag = 1;
    }
    if (flag == 0) {
      break;
    }
  }
  cout << x[a] + x[b] - x[c] << " " << y[a] + y[b] - y[c] << endl;
  cout << x[b] + x[c] - x[a] << " " << y[b] + y[c] - y[a] << endl;
  cout << x[c] + x[a] - x[b] << " " << y[c] + y[a] - y[b] << endl;
}
