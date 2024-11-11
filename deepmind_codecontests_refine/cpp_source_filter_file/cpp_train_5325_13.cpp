#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> a((size_t)n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << (count(a.begin(), a.end(), *min_element(a.begin(), a.end()) <= n / 2)
               ? "Alice"
               : "Bob")
       << endl;
  return 0;
}
