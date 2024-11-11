#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> poss;
  for (int i = 1; i <= 1000; i++) {
    int t = i, sum = 0;
    while (t > 0) {
      sum += t % 10;
      t = t / 10;
    }
    if (sum % 4 == 0) poss.push_back(i);
  }
  auto it = lower_bound(poss.begin(), poss.end(), n);
  cout << *it << endl;
}
