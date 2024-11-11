#include <bits/stdc++.h>
using namespace std;
int k, n;
string a;
vector<int> v;
bool cmp(int x, int y) { return a[x] < a[y]; }
string solve() {
  for (int i = 0; i < (int)a.size(); i++) v.push_back(i);
  string now = "";
  while (k > 0) {
    int ok = 0;
    sort(v.begin(), v.end(), cmp);
    for (int i = 'a', j = 0, nj = 0; i <= 'z'; i++, j = nj) {
      long long cnt = 0, cntd = 0;
      while (nj < (int)v.size() && a[v[nj]] == i) {
        cnt += n - v[nj];
        ++cntd;
        ++nj;
      }
      if (cntd == 0)
        continue;
      else if (cnt < k) {
        k -= cnt;
      } else if (cntd < k) {
        k -= cntd;
        vector<int> r;
        for (int x = j; x < nj; x++)
          if (v[x] + 1 < n) r.push_back(v[x] + 1);
        v = r;
        now = now + (char)i;
        ok = 1;
        break;
      } else {
        return now + (char)i;
      }
    }
    if (!ok) break;
  }
  return "No such line.";
}
int main(void) {
  cin >> a >> k;
  n = (int)a.size();
  string now = solve();
  printf("%s\n", now.c_str());
  return 0;
}
