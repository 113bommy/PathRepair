#include <bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int> > > edgelist;
int par[10005];
int fp(int c) {
  if (par[c] != c) return par[c] = fp(par[c]);
  return par[c];
}
int mst(int n) {
  int ret = 0;
  for (int a = 0; a < n; a++) par[a] = a;
  for (int z = 0; z < edgelist.size(); z++) {
    int L = edgelist[z].second.first, R = edgelist[z].second.second;
    int W = edgelist[z].first;
    int p1 = fp(L), p2 = fp(R);
    if (p1 != p2) {
      cout << L << " " << R << " >> " << W << endl;
      par[p1] = p2;
      ret += W;
    }
  }
  return ret;
}
int main() {
  long long n;
  cin >> n;
  long long save = n;
  n--;
  long long ret = 0;
  long long pos = 2;
  long long count = 0;
  while (pos <= n) {
    ret += ((n / pos) + (n % pos >= (pos / 2))) * (pos / 2);
    pos *= 2;
    count++;
  }
  pos /= 2;
  if (n > pos) {
    ret += pos;
  }
  printf("%lld\n", ret);
  return 0;
}
