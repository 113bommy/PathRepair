#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, k, l, n, m;
  cin >> n >> k;
  long long kola = n;
  vector<vector<long long> > res;
  string s;
  cin >> s;
  long long moja = 0;
  while (kola--) {
    vector<long long> temp;
    for (i = 0; i < n - 1;) {
      if (s[i] == 'R' && s[i + 1] == 'L') {
        s[i] = 'L';
        s[i + 1] = 'R';
        moja++;
        temp.push_back(i + 1);
        i += 2;
      } else
        i++;
    }
    if (temp.size() > 0)
      res.push_back(temp);
    else
      break;
  }
  if (moja < k || res.size() > k) {
    cout << "-1";
    return 0;
  } else {
    i = 0;
    j = 0;
    long long sz = res.size();
    while (sz - i < k) {
      cout << "1 " << res[i][j++] << "\n";
      k--;
      if (j >= res[i].size()) {
        j = 0;
        i++;
      }
    }
    while (k > 0) {
      long long sz = res[i].size() - j;
      cout << sz << " ";
      while (j < res[i].size()) cout << res[i][j++] << " ";
      cout << " \n";
      i++;
      j = 0;
      k--;
    }
  }
}
