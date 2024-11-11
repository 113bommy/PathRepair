#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1E9;
int N, X, Y;
struct sofads {
  int id, x;
  vector<int> v;
  sofads() {}
  sofads(int _id, vector<int> _v) : id(_id), v(_v) {}
  bool operator<(const sofads &ano) const { return x < ano.x; }
} sofa[100005];
int cnts[100005][4], expect[4];
int main() {
  cin >> N >> X >> Y;
  for (int i = (0); i < (N); i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    sofa[i] = sofads(
        i, vector<int>({min(x1, x2), max(x1, x2), min(y1, y2), max(y1, y2)}));
  }
  for (int t = (0); t < (4); t++) {
    for (int i = (0); i < (N); i++) sofa[i].x = sofa[i].v[t] * (t & 1 ? -1 : 1);
    sort(sofa, sofa + N);
    int prev = 0;
    for (int i = (0); i < (N); i++) {
      int j = i;
      while (j < N && sofa[j].x == sofa[i].x) j++;
      for (int k = (i); k < (j); k++) {
        if (sofa[k].v[t] == sofa[k].v[t & 1])
          cnts[sofa[k].id][t] = prev;
        else
          cnts[sofa[k].id][t] = prev + j - i - 1;
      }
      prev += j - i;
      i = j - 1;
    }
  }
  for (int t = (0); t < (4); t++) cin >> expect[t];
  for (int i = (0); i < (N); i++) {
    bool ok = true;
    for (int t = (0); t < (4); t++) {
      if (cnts[i][t] != expect[t]) ok = false;
    }
    if (ok) return printf("%d\n", i + 1), 0;
  }
  puts("-1");
  return 0;
}
