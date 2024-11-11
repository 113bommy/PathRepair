#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int q;
  cin >> q;
  while (q) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> v(n), o;
    for (long long int i = 0; i < n; i++) {
      cin >> v[i];
      if (v[i] % 2 != 0) {
        o.push_back(i);
      }
    }
    long long int qty = o.size();
    if (qty < k) {
      cout << "NO\n";
      q--;
      continue;
    }
    if (qty % 2 == 0 && k % 2 != 0) {
      cout << "NO";
      q--;
      continue;
    }
    if (k % 2 == 0 && qty % 2 != 0) {
      cout << "NO";
      q--;
      continue;
    }
    cout << "YES\n";
    for (long long int i = 0; i < k - 1; i++) {
      cout << o[i] + 1 << " ";
    }
    cout << n << endl;
    q--;
  }
}
