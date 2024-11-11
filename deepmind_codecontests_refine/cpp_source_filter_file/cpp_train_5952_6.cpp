#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const int N = 2 * 1e5 + 10;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long q, i, maxi = 0, n, k, sum, x, siz, y;
  vector<int> v;
  map<int, int> h;
  cin >> q;
  while (q--) {
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> x;
      h[x]++;
    }
    for (auto t : h) {
      v.push_back(t.second);
    }
    sort(v.begin(), v.end(), greater<int>());
    sum = v[0];
    k = sum;
    siz = v.size();
    for (i = 1; i < siz && k > 0; i++) {
      if (v[i] >= k) {
        sum += k - 1;
        k = k - 1;
      } else {
        sum += v[i];
        k = y;
      }
    }
    cout << sum << endl;
    v.clear();
    h.clear();
  }
  return 0;
}
