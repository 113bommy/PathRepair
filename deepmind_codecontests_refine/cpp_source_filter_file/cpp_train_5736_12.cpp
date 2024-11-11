#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[200007];
int bx[200007];
long long mod = 1e9 + 7;
long long rec(int l, int r) {
  if (l == r) {
    if (bx[l] == 1) return 1;
    return 0;
  }
  int m = (l + r) / 2;
  int cp = 0;
  vector<int> pr(0);
  vector<int> sf(0);
  for (int i = m; i >= l; i--) {
    cp += bx[i];
    pr.push_back(cp);
  }
  cp = 0;
  for (int i = m + 1; i <= r; i++) {
    cp += bx[i];
    sf.push_back(cp);
  }
  sort(sf.begin(), sf.end());
  sort(pr.begin(), pr.end());
  int j = sf.size();
  long long res = 0;
  for (int i = 0; i < pr.size(); i++) {
    while (j > 0 && pr[i] + sf[j - 1] > 0) j--;
    res += sf.size() - j;
  }
  return res + rec(l, m) + rec(m + 1, r);
}
int get(int x) {
  for (int i = 0; i < n; i++) {
    if (a[i] > x)
      bx[i] = 1;
    else
      bx[i] = -1;
  }
  return rec(0, n - 1);
}
int getsmp(int x) {
  vector<int> bf(0);
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int o = i; o < n; o++) {
      bf.clear();
      for (int k = i; k <= o; k++) bf.push_back(a[k]);
      sort(bf.begin(), bf.end());
      if (bf[(bf.size() - 1) / 2] > x) res++;
    }
  }
  return res;
}
int main() {
  srand(time(NULL));
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << get(k - 1) - get(k) << endl;
  return 0;
}
