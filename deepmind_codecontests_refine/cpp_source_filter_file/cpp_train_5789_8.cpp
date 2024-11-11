#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long n, x, y, a, b, c, t, q;
  string s;
  long long m[] = {4, 3, 2, 0, 1, 4, 3, 0, 2, 1, 4, 0, 3, 2, 1, 0};
  {
    vector<long long> v, v1;
    c = 1;
    map<long long, long long> make_pair;
    for (int i = (1); i < (17); i++) {
      cin >> x;
      v1.push_back(x);
      if (x) {
        if (i % 4 == 0) {
          v.push_back(i / 4);
        } else
          make_pair[m[i - 1]]++;
      }
    }
    bool f = 1, first = 0;
    for (int i = (0); i < (v.size()); i++) {
      for (int j = ((((v[i] / 4) - 1) * 4)); j < ((v[i] / 4)); j++)
        if (v1[j]) {
          first = 1;
          break;
        }
    }
    for (int i = (0); i < (v.size()); i++) {
      if (make_pair[v[i]] or first) {
        f = 0;
        break;
      }
    }
    if (f)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
