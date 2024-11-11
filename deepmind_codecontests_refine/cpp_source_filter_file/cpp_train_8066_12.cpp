#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > posOdd, posEven;
  int even = 0, odd = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a < 0) {
      posOdd.push_back(make_pair(a, b));
      odd++;
    } else {
      posEven.push_back(make_pair(a, b));
      even++;
    }
  }
  int cOdd, cEven;
  sort(posOdd.begin(), posOdd.end());
  sort(posEven.begin(), posEven.end());
  if (odd > even) {
    cOdd = even + 1;
    cEven = even;
  } else if (odd < even) {
    cOdd = odd;
    cEven = odd + 1;
  } else {
    cOdd = cEven = odd;
  }
  int sum = 0;
  for (int i = 0; i < cOdd; i++) {
    sum += posOdd[i].second;
  }
  for (int i = 0; i < cEven; i++) {
    sum += posEven[i].second;
  }
  cout << sum;
  return 0;
}
