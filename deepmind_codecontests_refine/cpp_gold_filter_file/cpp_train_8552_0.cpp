#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, i, q, c = 0, a, d, w = 0;
  cin >> n;
  q = n * 2;
  vector<long long int> v;
  for (i = 0; i < q; i++) {
    cin >> a;
    v.emplace_back(a);
    if (a > w) {
      c++;
    }
    w = a;
  }
  sort(v.begin(), v.end());
  if (v[0] == v[q - 1]) {
    cout << "-1"
         << "\n";
    return 0;
  }
  if (c == q) {
    swap(v.back(), v[0]);
  }
  for (i = q - 1; i >= 0; i--) {
    cout << v[i] << " ";
  }
  return 0;
}
