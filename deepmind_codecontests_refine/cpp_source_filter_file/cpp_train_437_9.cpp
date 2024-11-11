#include <bits/stdc++.h>
using namespace std;
int main() {
  long int t, a, n;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> n;
    set<long int> name;
    for (long int i = 0; i < n; i++) {
      long int k;
      cin >> k;
      name.insert(k);
    }
    cout << name.size();
  }
}
