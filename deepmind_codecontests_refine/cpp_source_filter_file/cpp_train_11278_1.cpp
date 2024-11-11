#include <bits/stdc++.h>
using namespace std;
int a, b, m, r[100005], n, i, j, k, l;
pair<int, int> o[100005];
int main() {
  cin >> a >> b >> m >> r[0];
  i = 1;
  while (i < m) {
    r[i] = (a * r[i - 1] + b) % m;
    if (o[r[i]].first < 1) {
      o[r[i]].first++;
      o[r[i]].second = i;
    } else {
      l = o[r[i]].second - i;
      break;
    }
    i++;
  }
  cout << abs(l);
}
