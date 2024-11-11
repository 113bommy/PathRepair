#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, k;
  cin >> n >> k;
  set<long long int> s;
  long long int i;
  for (i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      s.insert(i);
      s.insert(n / i);
    }
  }
  if (k > s.size()) {
    cout << "-1"
         << "\n";
  } else {
    cout << *next(s.begin(), k - 1);
  }
  return 0;
}
