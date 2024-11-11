#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v;
  int i = 3;
  while (k > 1 && n > 1) {
    if (!(n % 2)) {
      n = n / 2;
      v.push_back(2);
      k--;
    } else {
      if (!(n % i)) {
        n = n / i;
        v.push_back(i);
        k--;
      } else
        i += 2;
    }
  }
  if (n <= 1 && k >= 1)
    cout << -1;
  else {
    cout << n << " ";
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  }
  cout << endl;
  return 0;
}
