#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  ifstream from;
  const int err = 0;
  const long long nmin = 1, nmax = 1000000000, mmin = 1, mmax = 100;
  long long n, m, res, rt, rm, i, j, k, ax;
  if (0) from.open("test.txt");
  cin >> n >> m >> k;
  vector<long long> di(m), pi(k), v;
  for (i = 0; i < m; i++) cin >> di[i];
  for (i = 0; i < k; i++) cin >> pi[i];
  res = k + 1;
  for (i = 0; i < m; i++) {
    rt = 0;
    for (j = 0; j < k; j++) {
      if (pi[j] % di[i] == 0) rt++;
    }
    if (rt < res) {
      res = rt;
      v.clear();
      v.push_back(i + 1);
    } else if (rt = res)
      v.push_back(i + 1);
  }
  rm = v.size();
  cout << rm << endl;
  for (i = 0; i < rm - 1; i++) cout << v[i] << ' ';
  if (rm > 0) cout << v[rm - 1] << endl;
  return 0;
}
