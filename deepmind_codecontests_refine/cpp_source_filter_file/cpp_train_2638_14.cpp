#include <bits/stdc++.h>
using namespace std;
const int SIZE = 200 << 10;
int h, m, n;
int k;
bool used[SIZE];
pair<int, int> place[SIZE];
set<int> empty[SIZE];
map<int, pair<int, int> > elems;
char buff[1024];
int main() {
  gets(buff);
  sscanf(buff, "%d%d%d", &h, &m, &n);
  for (int i = 0; i < h; i++) {
    if (used[i]) continue;
    int qq = 0;
    int curr = i;
    do {
      used[curr] = true;
      place[curr] = pair<int, int>(k, qq);
      empty[k].insert(qq);
      qq++;
      curr += m;
      curr %= h;
    } while (!used[curr]);
    k++;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    gets(buff);
    char ch;
    int id, hf;
    sscanf(buff, " %c%d%d", &ch, &id, &hf);
    if (ch == '+') {
      pair<int, int> pl = place[hf];
      set<int>::iterator it;
      it = empty[pl.first].lower_bound(pl.second);
      if (it == empty[pl.first].end()) it = empty[pl.first].begin();
      assert(it != empty[pl.first].end());
      int ind = *it;
      int addtoans = ind - pl.second;
      if (addtoans < 0) addtoans += h;
      ans += addtoans;
      empty[pl.first].erase(ind);
      elems[id] = pair<int, int>(pl.first, ind);
    } else {
      pair<int, int> pl = elems[id];
      elems.erase(id);
      empty[pl.first].insert(pl.second);
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
