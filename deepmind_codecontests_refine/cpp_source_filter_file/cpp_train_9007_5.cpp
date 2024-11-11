#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int match[N], nx[N], prv[N], incc[N], decc[N];
stack<int> inds;
string s, q;
int main(int argc, char const *argv[]) {
  int n, m, p;
  cin >> n >> m >> p;
  cin >> s >> q;
  incc[0] = 1;
  decc[n + 1] = n;
  prv[n + 1] = n;
  nx[0] = 1;
  for (int i = 0; i < n; i++) {
    incc[i + 1] = i + 2;
    decc[i + 1] = i;
    if (s[i] == '(')
      inds.push(i + 1);
    else {
      int x = inds.top();
      inds.pop();
      match[x] = i + 1;
      match[i + 1] = x;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == '(') {
      prv[i] = decc[i];
      prv[match[i]] = decc[i];
    } else if (s[i - 1] == ')') {
      nx[i] = incc[i];
      nx[match[i]] = incc[i];
    }
  }
  for (int i = 0; i < m; i++) {
    if (q[i] == 'R') {
      p = incc[p];
    } else if (q[i] == 'L')
      p = decc[p];
    else {
      int pp = nx[p];
      int qq = prv[p];
      int xx = min(p, match[p]);
      int yy = max(p, match[p]);
      int aa = incc[yy];
      int bb = decc[xx];
      int cc = prv[xx];
      int dd = nx[yy];
      if (prv[dd] >= xx && prv[dd] <= yy) {
        prv[dd] = cc;
        prv[match[dd]] = cc;
      }
      if (nx[cc] >= xx && nx[cc] <= yy) {
        nx[cc] = dd;
        nx[match[cc]] = dd;
      }
      incc[bb] = aa;
      decc[aa] = bb;
      if (pp != n)
        p = pp;
      else
        p = qq;
    }
  }
  int ii = 0;
  while (1) {
    ii = incc[ii];
    if (ii != n + 1)
      cout << s[ii - 1];
    else
      break;
  }
  cout << "\n";
  return 0;
}
