#include <bits/stdc++.h>
using namespace std;
int a[25];
pair<char, int> x[25];
bool z[2100000];
int d[2100000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  reverse(a, a + n);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x[i].first >> x[i].second;
  }
  reverse(x, x + m);
  for (int i = 0; i < (1 << m); i++) {
    z[i] = false;
    d[i] = 0;
  }
  z[0] = true;
  for (int i = 0; i < (1 << m); i++) {
    int cnt = 0;
    for (int j = 0; j < m; j++)
      if ((i & (1 << j)) > 0) {
        cnt++;
      }
    if (cnt < m) {
      for (int j = 0; j < m; j++)
        if ((i & (1 << j)) == 0) {
          if (x[cnt].second == 1) {
            int plus = 0;
            if (x[cnt].first == 'p') plus = a[j];
            if (z[i + (1 << j)])
              d[i + (1 << j)] = max(d[i + (1 << j)], d[i] + plus);
            else
              d[i + (1 << j)] = d[i] + plus;
            z[i + (1 << j)] = true;
          } else {
            int plus = 0;
            if (x[cnt].first == 'p') plus = a[j];
            if (z[i + (1 << j)])
              d[i + (1 << j)] = min(d[i + (1 << j)], d[i] - plus);
            else
              d[i + (1 << j)] = d[i] - plus;
            z[i + (1 << j)] = true;
          }
        }
    }
  }
  cout << d[(1 << m) - 1];
  return 0;
}
