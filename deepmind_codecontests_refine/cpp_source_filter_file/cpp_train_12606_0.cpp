#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, sumf = 0, sums = 0;
  cin >> n >> m;
  int *arrd = new int[n];
  pair<int, int> *arr = new pair<int, int>[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
    sumf += arr[i].first;
    sums += arr[i].second;
    arrd[i] = arr[i].first - arr[i].second;
  }
  sort(arrd, arrd + n);
  if (sumf <= m)
    cout << 0;
  else if (sums > m)
    cout << -1;
  else {
    int sumt = 0, c = 0;
    for (int i = n - 1; i >= 0; i--) {
      sumt += arrd[i];
      c++;
      if (sumf - sumt <= m) break;
    }
    cout << c;
  }
  return 0;
}
