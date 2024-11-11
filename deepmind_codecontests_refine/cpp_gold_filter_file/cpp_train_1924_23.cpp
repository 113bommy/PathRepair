#include <bits/stdc++.h>
using namespace std;
inline void pr(int n) { printf("%d\n", n); }
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  for (int i = 0; i < ((int)((t).size())); i++) s << t[i] << " ";
  return s;
}
map<vector<int>, int> invmap;
int getinv(vector<int> a) {
  if (invmap.count(a) != 0) return invmap[a];
  int inv = 0;
  for (int i = 0; i < a.size(); i++)
    for (int j = i + 1; j < a.size(); j++) {
      if (a[i] > a[j]) inv++;
    }
  invmap[a] = inv;
  return inv;
}
double gettotinv(vector<int> a, int k) {
  if (k == 0)
    return getinv(a);
  else {
    double totinv = 0, tot = 0;
    for (int l = 0; l < a.size(); l++)
      for (int r = l; r < a.size(); r++) {
        tot++;
        reverse(a.begin() + l, a.begin() + r + 1);
        totinv += gettotinv(a, k - 1);
        reverse(a.begin() + l, a.begin() + r + 1);
      }
    return ((double)totinv) / tot;
  }
}
int main() {
  int(n), (k);
  scanf("%d %d", &(n), &(k));
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int(x);
    scanf("%d", &(x));
    arr.push_back(x);
  }
  printf("%.12lf", gettotinv(arr, k));
}
