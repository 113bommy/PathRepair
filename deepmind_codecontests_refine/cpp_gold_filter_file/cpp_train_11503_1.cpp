#include <bits/stdc++.h>
using namespace std;
long long int h[200001];
long long int d[200001];
int main() {
  long long int n, m;
  cin >> n >> m;
  bool sol = true;
  cin >> h[0] >> d[0];
  long long int i = 1;
  while (i < m) {
    cin >> h[i] >> d[i];
    if (abs(d[i] - d[i - 1]) > h[i] - h[i - 1]) sol = false;
    i++;
  }
  long long int hmax = d[0];
  for (long long int j = 1; j < h[0]; j++) {
    long long int hh = (d[0] + h[0] - j);
    if (hh < 0) hh = 0;
    if (hh > hmax) hmax = hh;
  }
  for (long long int i = 1; i < m; i++) {
    long long int w = h[i] - h[i - 1];
    for (long long int j = h[i - 1]; j <= h[i]; j++) {
      long long int hh = min(d[i - 1] + j - h[i - 1], d[i] + h[i] - j);
      if (hh > hmax) hmax = hh;
    }
  }
  for (long long int j = h[m - 1] + 1; j <= n; j++) {
    long long int hh = (d[m - 1] + j - h[m - 1]);
    if (hh > hmax) hmax = hh;
  }
  if (sol)
    cout << hmax << endl;
  else
    cout << "IMPOSSIBLE" << endl;
  return 0;
}
