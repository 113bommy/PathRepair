#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000,1000000000")
using namespace std;
const long long inf = 1e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
struct item {
  string Name, Class;
  long long atk, def, res, size;
} x[105];
struct resident {
  string Name, Type;
  long long bonus;
  string Home;
  friend bool operator<(resident a, resident b) { return a.bonus > b.bonus; }
} all[1005];
map<string, long long> where;
long long cnt[105];
long long n, m;
vector<resident> atk, def, res;
long long prefa[1005], prefb[1005], prefc[1005];
int main(void) {
  cin >> n;
  for (long long(i) = 0; (i) < (long long)(n); (i)++) {
    cin >> x[i].Name >> x[i].Class >> x[i].atk >> x[i].def >> x[i].res >>
        x[i].size;
    where[x[i].Name] = i;
  }
  cin >> m;
  for (long long(i) = 0; (i) < (long long)(m); (i)++) {
    resident now;
    cin >> now.Name >> now.Type >> now.bonus >> now.Home;
    all[i] = now;
    if (now.Type == "gladiator") atk.push_back(now);
    if (now.Type == "sentry") def.push_back(now);
    if (now.Type == "physician") res.push_back(now);
    cnt[where[now.Home]]++;
  }
  sort((atk).begin(), (atk).end());
  sort((def).begin(), (def).end());
  sort((res).begin(), (res).end());
  if (atk.size()) prefa[1] = atk[0].bonus;
  if (def.size()) prefb[1] = def[0].bonus;
  if (res.size()) prefc[1] = res[0].bonus;
  for (long long(i) = 0; (i) < (long long)((long long)atk.size() - 1); (i)++)
    prefa[i + 2] = prefa[i + 1] + atk[i + 1].bonus;
  for (long long(i) = 0; (i) < (long long)((long long)def.size() - 1); (i)++)
    prefb[i + 2] = prefb[i + 1] + def[i + 1].bonus;
  for (long long(i) = 0; (i) < (long long)((long long)res.size() - 1); (i)++)
    prefc[i + 2] = prefc[i + 1] + res[i + 1].bonus;
  bool ok = 0;
  for (long long(i) = 0; (i) < (long long)(n); (i)++) {
    if (cnt[i] != x[i].size) {
      ok = 1;
      break;
    }
  }
  if (!ok) {
    long long ax = 0, bx = 0, cx = 0;
    vector<string> name;
    for (long long(i) = 0; (i) < (long long)(atk.size()); (i)++)
      x[where[atk[i].Home]].atk += atk[i].bonus;
    for (long long(i) = 0; (i) < (long long)(def.size()); (i)++)
      x[where[def[i].Home]].def += def[i].bonus;
    for (long long(i) = 0; (i) < (long long)(res.size()); (i)++)
      x[where[res[i].Home]].res += res[i].bonus;
    for (long long(i) = 0; (i) < (long long)(n); (i)++) {
      if (x[i].Class == "weapon") ax = i;
      if (x[i].Class == "armor") bx = i;
      if (x[i].Class == "orb") cx = i;
    }
    for (long long(i) = 0; (i) < (long long)(n); (i)++) {
      if (x[i].Class == "weapon" && x[i].atk > x[ax].atk) ax = i;
      if (x[i].Class == "armor" && x[i].def > x[bx].def) bx = i;
      if (x[i].Class == "orb" && x[i].res > x[cx].res) cx = i;
    }
    name.clear();
    cout << x[ax].Name << " ";
    for (long long(i) = 0; (i) < (long long)(m); (i)++)
      if (where[all[i].Home] == ax) name.push_back(all[i].Name);
    cout << name.size();
    if (name.size()) cout << " ";
    for (long long(i) = 0; (i) < (long long)(name.size()); (i)++)
      cout << name[i] << " ";
    cout << endl;
    name.clear();
    cout << x[bx].Name << " ";
    for (long long(i) = 0; (i) < (long long)(m); (i)++)
      if (where[all[i].Home] == bx) name.push_back(all[i].Name);
    cout << name.size();
    if (name.size()) cout << " ";
    for (long long(i) = 0; (i) < (long long)(name.size()); (i)++)
      cout << name[i] << " ";
    cout << endl;
    name.clear();
    cout << x[cx].Name << " ";
    for (long long(i) = 0; (i) < (long long)(m); (i)++)
      if (where[all[i].Home] == cx) name.push_back(all[i].Name);
    cout << name.size();
    if (name.size()) cout << " ";
    for (long long(i) = 0; (i) < (long long)(name.size()); (i)++)
      cout << name[i] << " ";
    cout << endl;
    exit(0);
  }
  long long ax = 0, bx = 0, cx = 0;
  for (long long(i) = 0; (i) < (long long)(n); (i)++) {
    if (x[i].Class == "weapon") ax = i;
    if (x[i].Class == "armor") bx = i;
    if (x[i].Class == "orb") cx = i;
  }
  for (long long(i) = 0; (i) < (long long)(n); (i)++) {
    long long mx = min(x[i].size, (long long)atk.size());
    long long my = min(x[i].size, (long long)def.size());
    long long mz = min(x[i].size, (long long)res.size());
    long long gx = min(x[ax].size, (long long)atk.size());
    long long gy = min(x[bx].size, (long long)def.size());
    long long gz = min(x[cx].size, (long long)res.size());
    if (x[i].Class == "weapon" && x[i].atk + prefa[mx] > x[ax].atk + prefa[gx])
      ax = i;
    if (x[i].Class == "armor" && x[i].def + prefb[my] > x[bx].def + prefb[gy])
      bx = i;
    if (x[i].Class == "orb" && x[i].res + prefc[mz] > x[cx].res + prefc[gz])
      cx = i;
  }
  vector<string> name;
  vector<string> px, py, pz;
  long long lx = 0, ly = 0, lz = 0;
  name.clear();
  for (long long(i) = 0;
       (i) < (long long)(min(x[ax].size, (long long)atk.size())); (i)++)
    name.push_back(atk[i].Name), lx++;
  px = name;
  name.clear();
  for (long long(i) = 0;
       (i) < (long long)(min(x[bx].size, (long long)def.size())); (i)++)
    name.push_back(def[i].Name), ly++;
  py = name;
  name.clear();
  for (long long(i) = 0;
       (i) < (long long)(min(x[cx].size, (long long)res.size())); (i)++)
    name.push_back(res[i].Name), lz++;
  pz = name;
  while (px.size() < x[ax].size && ly < def.size())
    px.push_back(def[ly].Name), ly++;
  while (px.size() < x[ax].size && lz < res.size())
    px.push_back(res[lz].Name), lz++;
  while (py.size() < x[bx].size && lx < atk.size())
    py.push_back(atk[lx].Name), lx++;
  while (py.size() < x[bx].size && lz < res.size())
    py.push_back(res[lz].Name), lz++;
  while (pz.size() < x[cx].size && ly < def.size())
    pz.push_back(def[ly].Name), ly++;
  while (pz.size() < x[cx].size && lx < atk.size())
    pz.push_back(atk[lx].Name), lx++;
  cout << x[ax].Name << " " << px.size();
  if (px.size()) cout << " ";
  for (long long(i) = 0; (i) < (long long)(px.size()); (i)++)
    cout << px[i] << " ";
  cout << endl;
  cout << x[bx].Name << " " << py.size();
  if (py.size()) cout << " ";
  for (long long(i) = 0; (i) < (long long)(py.size()); (i)++)
    cout << py[i] << " ";
  cout << endl;
  cout << x[cx].Name << " " << pz.size();
  if (pz.size()) cout << " ";
  for (long long(i) = 0; (i) < (long long)(pz.size()); (i)++)
    cout << pz[i] << " ";
  cout << endl;
  return 0;
}
