#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, q, c = 0;
  cin >> n >> k >> q;
  vector<long long> v(n);
  map<long long, long long> r;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<pair<long long, long long>> w(q);
  map<long long, long long> p;
  for (long long i = 0; i < q; i++) {
    cin >> w[i].first >> w[i].second;
    if (w[i].first == 1) {
      if (c < k || p[w[i].second] == 1) {
        p[w[i].second] = 1;
        r[v[w[i].second - 1]] = w[i].second;
      } else
        for (map<long long, long long>::iterator it = r.begin(); it != r.end();
             it++) {
          if (v[w[i].second - 1] > it->first && p[it->second]) {
            p[w[i].second] = 1;
            p[it->second] = 0;
            r.erase(it);
            r[v[w[i].second - 1]] = w[i].second;
            break;
          }
        }
      c++;
    } else {
      if (p[w[i].second])
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
