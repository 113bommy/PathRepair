#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > s;
set<pair<int, int> >::iterator its;
pair<int, int> p, p1, p2;
map<int, int> m;
map<int, int>::iterator itm;
struct st {
  int a, b, c;
};
int i, n, k, v[3], z;
int main() {
  st stt[100003];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> k;
    m[k]++;
  }
  for (itm = m.begin(); itm != m.end(); itm++) {
    p.first = (-1 * (itm->second));
    p.second = itm->first;
    s.insert(p);
  }
  while (s.size() >= 3) {
    its = s.begin();
    p = *its;
    s.erase(s.begin());
    its = s.begin();
    p1 = *its;
    s.erase(s.begin());
    its = s.begin();
    p2 = *its;
    s.erase(s.begin());
    v[0] = p.second;
    v[1] = p1.second;
    v[2] = p2.second;
    sort(v, v + 3);
    stt[z].a = v[2];
    stt[z].b = v[1];
    stt[z].c = v[0];
    p.first++;
    p1.first++;
    p2.first++;
    if (p.first != 0) s.insert(p);
    if (p1.first != 0) s.insert(p1);
    if (p2.first != 0) s.insert(p2);
    z++;
  }
  cout << z << endl;
  for (i = 0; i < z; i++) {
    cout << stt[i].a << " " << stt[i].b << " " << stt[i].c << endl;
  }
}
