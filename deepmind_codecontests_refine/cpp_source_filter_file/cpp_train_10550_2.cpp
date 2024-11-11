#include <bits/stdc++.h>
using namespace std;
class UFDS {
 private:
  vector<int> p, rank, setSize;
  int numSets;

 public:
  UFDS(int n) {
    setSize.assign(n, 1);
    numSets = n;
    rank.assign(n, 0);
    p.assign(n, 0);
    for (int i = 0; i < n; i++) p[i] = i;
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      numSets--;
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
        setSize[x] += setSize[y];
      } else {
        p[x] = y;
        setSize[y] += setSize[x];
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  long long x[50000] = {0}, i, c, t, s, e, m;
  cin >> c;
  for (i = 1; i < 50000; i++) x[i] = i * (i + 1) / 2;
  for (i = 0; i < 50000; i++) {
    t = c - x[i];
    if (t < 0) break;
    s = 0;
    e = 49999;
    while (s < e) {
      m = (s + e) / 2;
      if (x[m] == t)
        return cout << "YES", 0;
      else if (x[m] < t)
        s = m + 1;
      else
        e = m - 1;
    }
  }
  cout << "NO";
  return 0;
}
