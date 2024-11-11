#include <bits/stdc++.h>
using namespace std;
int calc(int k) {
  int res = 0;
  while (!(k % 10)) {
    ++res;
    k /= 10;
  }
  return res;
}
int main() {
  string s;
  cin >> s;
  int n = s.size();
  string res1, res2;
  map<int, int> m1, m2;
  for (int i = 0; i < (s.size()); ++i) {
    ++m1[s[i] - '0'];
    ++m2[s[i] - '0'];
  }
  res1.reserve(n);
  res2.reserve(n);
  res1.clear();
  res2.clear();
  int besti = -1, bestj = -1, best = 0, bestzer = 0;
  for (int i(1); i < (10); ++i)
    for (int j = 0; j < (10); ++j)
      if (((i + j) % 10 == 0) && m1[i] && m2[j]) {
        int ctr = 1;
        --m1[i];
        --m2[j];
        int zer1 = 0, zer2 = 0;
        for (int ii = 0; ii < (10); ++ii)
          for (int jj = 0; jj < (10); ++jj)
            if (ii + jj == 9) {
              ctr += min(m1[ii], m2[jj]);
              if (ii == 0) zer1 = min(m1[ii], m2[jj]);
              if (jj == 0) zer2 = min(m1[ii], m2[jj]);
            }
        ctr += min(m1[0] - zer1, m2[0] - zer2);
        if (ctr > best) {
          best = ctr;
          besti = i;
          bestj = j;
          bestzer = min(m1[0] - zer1, m2[0] - zer2);
        }
        ++m1[i];
        ++m2[j];
      }
  if (besti != -1) {
    res1.append(bestzer, '0');
    res2.append(bestzer, '0');
    m1[0] -= bestzer;
    m2[0] -= bestzer;
    res1.push_back('0' + besti);
    res2.push_back('0' + bestj);
    --m1[besti];
    --m2[bestj];
    for (int i = 0; i < (10); ++i)
      for (int j = 0; j < (10); ++j)
        if (i + j == 9) {
          int t = min(m1[i], m2[j]);
          res1.append(t, '0' + i);
          res2.append(t, '0' + j);
          m1[i] -= t;
          m2[j] -= t;
        }
  }
  for (int i = 0; i < (10); ++i) res1.append(m1[i], '0' + i);
  for (int i = 0; i < (10); ++i) res2.append(m2[i], '0' + i);
  reverse(res1.begin(), res1.end());
  reverse(res2.begin(), res2.end());
  cout << res1 << endl;
  cout << res2 << endl;
  return 0;
}
