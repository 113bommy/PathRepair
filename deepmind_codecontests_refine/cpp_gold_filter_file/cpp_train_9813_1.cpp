#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int pos[N];
bool del[2 * N];
struct date {
  int val, ind;
  bool operator<(const date& rhs) const { return val < rhs.val; }
};
int main() {
  vector<date> v;
  int dbegin, dend;
  date tmp;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    tmp.ind = i;
    scanf("%d%d", &dbegin, &dend);
    tmp.val = dbegin;
    v.push_back(tmp);
    tmp.val = dend;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  int cnt(0);
  int ibegin(0);
  pos[v[ibegin].ind] = 0;
  for (int i = 1; i < v.size(); i++) {
    if (i <= ibegin) continue;
    if (v[i].ind == v[ibegin].ind) {
      del[i] = true;
      del[ibegin] = true;
      while (del[++ibegin])
        ;
      if (ibegin >= v.size()) break;
      if (!pos[v[ibegin].ind]) pos[v[ibegin].ind] = ibegin;
    } else if (!pos[v[i].ind]) {
      pos[v[i].ind] = i;
    } else {
      del[i] = true;
      del[pos[v[i].ind]] = true;
      cnt++;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
