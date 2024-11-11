#include <bits/stdc++.h>
using namespace std;
multiset<pair<int, int> > peoples;
vector<int> vt;
int main() {
  int n, M, T;
  scanf("%d%d%d", &n, &M, &T);
  for (int i = 0; i < n; i++) {
    int ho, mi, se;
    scanf("%d:%d:%d", &ho, &mi, &se);
    int time = ho * 60 * 60 + mi * 60 + se;
    vt.push_back(time);
  }
  vector<int> v;
  sort(vt.begin(), vt.end());
  bool checked = false;
  int counter = 0;
  for (unsigned int i = 0; i < vt.size();) {
    int cur_time = vt[i];
    while (!peoples.empty() && peoples.begin()->first + T <= cur_time) {
      peoples.erase(peoples.begin());
    }
    while (i < vt.size() && cur_time == vt[i]) {
      if (peoples.size() < M) {
        counter++;
        peoples.insert(make_pair(vt[i], counter));
        v.push_back(counter);
      } else {
        auto it = --peoples.end();
        pair<int, int> p = *it;
        p.first = cur_time;
        peoples.erase(it);
        peoples.insert(p);
        v.push_back(counter);
      }
      ++i;
    }
    if (peoples.size() == M) {
      checked = true;
    }
  }
  if (checked) {
    printf("%d\n", counter);
    for (unsigned int i = 0; i < v.size(); i++) {
      printf("%d\n", v[i]);
    }
  } else {
    printf("No solution\n");
  }
  return 0;
}
