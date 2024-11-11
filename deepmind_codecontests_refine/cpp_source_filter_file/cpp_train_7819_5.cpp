#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned int n, x, y, ma;
  cin >> n;
  pair<unsigned long, unsigned int> sal[n];
  for (int i = 0; i < n; i++) {
    cin >> sal[i].second;
    ma = 0;
    for (unsigned int j = 0; j < sal[i].second; j++) {
      cin >> y;
      if (y > ma) ma = y;
    }
    sal[i].first = ma;
  }
  sort(sal, sal + n);
  unsigned long long sum = 0;
  for (unsigned int i = 0; i < n - 1; i++) {
    sum += (sal[n - 1].first - sal[i].first) * sal[i].second;
  }
  cout << sum;
}
