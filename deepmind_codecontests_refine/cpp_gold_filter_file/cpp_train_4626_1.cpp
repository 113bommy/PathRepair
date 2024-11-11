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
  int x[101] = {0}, y, z, n, i, j, a, b, ans = 0;
  cin >> n;
  cin >> a >> b;
  for (i = 0; i < n - 1; i++) {
    cin >> y >> z;
    for (j = y; j < z; j++) x[j] = 1;
  }
  for (i = a; i < b; i++) {
    ans += !x[i];
  }
  cout << ans;
  return 0;
}
