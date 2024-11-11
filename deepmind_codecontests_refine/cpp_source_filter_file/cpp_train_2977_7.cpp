#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> vec;
  if (n == 1) {
    cout << -1;
  } else {
    for (int i = 2; i <= n; i++) {
      while (n % i == 0 && k > 1) {
        vec.push_back(i);
        n /= i;
        k--;
      }
      if (k <= 1) break;
    }
    vec.push_back(n);
    k--;
    if (k == 0) {
      for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
    } else
      cout << -1;
  }
}
