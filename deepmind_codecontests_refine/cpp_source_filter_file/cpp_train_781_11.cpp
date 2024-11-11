#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k, q;
  cin >> n >> k >> q;
  vector<long long> t(n, 0);
  map<long long, long long> c;
  for (long long i = 0; i < n; i++) {
    cin >> t[i];
    c[i + 1] = t[i];
  }
  vector<long long> temp;
  long long siz = min((long long)6, k);
  while (q--) {
    long long a, b;
    cin >> a >> b;
    sort(temp.begin(), temp.end());
    if (a == 1) {
      if (temp.size() < siz && !binary_search(temp.begin(), temp.end(), c[b])) {
        temp.push_back(c[b]);
      } else if (binary_search(temp.begin(), temp.end(), c[b]))
        continue;
      else {
        if (c[b] < temp[0]) continue;
        temp.erase(temp.begin());
        temp.push_back(c[b]);
      }
    } else if (a == 2) {
      if (binary_search(temp.begin(), temp.end(), c[b]))
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
}
