#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  k--;
  vector<int> divs;
  while (k) {
    bool found = false;
    for (int i = 2; i <= sqrt(n); i++) {
      if (n % i == 0) {
        divs.push_back(i);
        n /= i;
        k--;
        found = true;
        break;
      }
    }
    if (k > 0 && !found) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (auto it = divs.begin(); it != divs.end(); it++) {
    cout << *it << " ";
  }
  cout << n << endl;
}
