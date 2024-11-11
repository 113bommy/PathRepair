#include <bits/stdc++.h>
using namespace std;
inline void pisz(int n) { printf("%d\n", n); }
template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  for (int(i) = 0; (i) < (((int)(t.size()))); ++(i)) s << t[i] << " ";
  return s;
}
int temp1[100007], temp2[100007], v[100007], num[100007];
int k, n;
bool select(long double t, bool go = 0) {
  int ktory = k;
  vector<int> res;
  for (int(i) = (n - 1); (i) >= (0); --i) {
    if (ktory <= t * v[i]) {
      ktory--;
      if (go) res.push_back(num[i]);
      if (ktory == 0) {
        if (go) {
          for (int(j) = (((int)(res.size())) - 1); (j) >= (0); --j)
            printf("%d ", res[j]);
        }
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  int(nn), (kk), (syf);
  scanf("%d %d %d", &(nn), &(kk), &(syf));
  n = nn;
  k = kk;
  for (int(i) = 0; (i) < (n); ++(i)) scanf("%d", temp1 + i);
  for (int(i) = 0; (i) < (n); ++(i)) scanf("%d", temp2 + i);
  vector<pair<pair<int, int>, int> > vec;
  for (int(i) = 0; (i) < (n); ++(i))
    vec.push_back(make_pair(make_pair(temp1[i], temp2[i]), i + 1));
  sort(vec.begin(), vec.end());
  for (int(i) = 0; (i) < (n); ++(i)) {
    num[i] = vec[i].second;
    v[i] = vec[i].first.second;
  }
  long double best = 100000, from = 0, to = best;
  for (int(u) = 0; (u) < (50); ++(u)) {
    long double teraz = (from + to) / 2;
    bool mozna = select(teraz);
    if (mozna) {
      (best) = min((best), (teraz));
      ;
      to = teraz;
    } else {
      from = teraz;
    }
  }
  select(best, 1);
}
