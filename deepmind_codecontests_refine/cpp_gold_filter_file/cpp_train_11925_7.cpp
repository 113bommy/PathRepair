#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int len1 = 0, len2 = 0;
  int n, m;
  cin >> n >> m;
  int u = n - 1, v = m - 1;
  n--, m--;
  do {
    len1++;
    n /= 7;
  } while (n > 0);
  do {
    len2++;
    m /= 7;
  } while (m > 0);
  vector<int> f = {0, 1, 2, 3, 4, 5, 6};
  set<vector<int> > valid;
  if (len1 + len2 <= (int)f.size()) do {
      int first = 0, second = 0;
      vector<int> cur;
      for (int i = 0; i < len1; i++) {
        first = first * 7 + f[i];
        cur.push_back(f[i]);
      }
      for (int j = 0; j < len2; j++) {
        second = second * 7 + f[j + len1];
        cur.push_back(f[j + len1]);
      }
      if (first <= u && second <= v && !valid.count(cur)) {
        valid.insert(cur);
      }
    } while (next_permutation(f.begin(), f.end()));
  cout << (int)valid.size() << endl;
}
