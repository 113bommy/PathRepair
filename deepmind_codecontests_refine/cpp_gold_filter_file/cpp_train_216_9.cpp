#include <bits/stdc++.h>
using namespace std;
map<string, int> Size, atk, def, res, Left;
map<string, string> Kind;
set<string> used;
map<string, vector<string> > M;
string weapon, armor, orb;
string C[1010], Tp[1010], Home[1010];
int n, m, Bonus[1010], Flag;
void doit(string weapon) {
  for (; M[weapon].size() < Size[weapon];) {
    Flag = 0;
    for (int i = 1; i <= m; i++)
      if (!used.count(C[i])) {
        Flag = 1;
        used.insert(C[i]);
        M[weapon].push_back(C[i]);
        break;
      }
    if (!Flag) break;
  }
  cout << M[weapon].size();
  for (int i = 0; i < M[weapon].size(); i++) cout << " " << M[weapon][i];
  cout << endl;
}
void check(int Bonus, string Tp, string Home) {
  if (Kind[Home] == "weapon" && Tp == "gladiator") atk[Home] += Bonus;
  if (Kind[Home] == "armor" && Tp == "sentry") def[Home] += Bonus;
  if (Kind[Home] == "orb" && Tp == "physician") res[Home] += Bonus;
}
void Sp() {
  for (int i = 1; i <= m; i++) check(Bonus[i], Tp[i], Home[i]);
  for (map<string, string>::iterator i = Kind.begin(); i != Kind.end(); i++)
    if (i->second == "weapon") {
      if (weapon == "" || atk[i->first] > atk[weapon]) weapon = i->first;
    } else if (i->second == "armor") {
      if (armor == "" || def[i->first] > def[armor]) armor = i->first;
    } else if (orb == "" || res[i->first] > res[orb])
      orb = i->first;
  int tot;
  cout << weapon << " ";
  tot = 0;
  for (int i = 1; i <= m; i++)
    if (Home[i] == weapon) tot++;
  cout << tot;
  for (int i = 1; i <= m; i++)
    if (Home[i] == weapon) cout << " " << C[i];
  cout << endl;
  cout << armor << " ";
  tot = 0;
  for (int i = 1; i <= m; i++)
    if (Home[i] == armor) tot++;
  cout << tot;
  for (int i = 1; i <= m; i++)
    if (Home[i] == armor) cout << " " << C[i];
  cout << endl;
  cout << orb << " ";
  tot = 0;
  for (int i = 1; i <= m; i++)
    if (Home[i] == orb) tot++;
  cout << tot;
  for (int i = 1; i <= m; i++)
    if (Home[i] == orb) cout << " " << C[i];
  cout << endl;
}
void work(string &s, string s1, string s2) {
  int Max = 0;
  vector<pair<int, string> > v;
  v.clear();
  for (int i = 1; i <= m; i++)
    if (Tp[i] == s2) v.push_back(make_pair(-Bonus[i], C[i]));
  sort(v.begin(), v.end());
  for (map<string, string>::iterator i = Kind.begin(); i != Kind.end(); i++)
    if (i->second == s1) {
      int cur;
      if (s1 == "weapon") cur = atk[i->first];
      if (s1 == "armor") cur = def[i->first];
      if (s1 == "orb") cur = res[i->first];
      for (int j = 1; j <= min(Size[i->first], (int)v.size()); j++)
        cur += (-v[j - 1].first);
      if (s == "" || cur > Max) s = i->first, Max = cur;
    }
  M[s].clear();
  for (int j = 1; j <= min(Size[s], (int)v.size()); j++)
    M[s].push_back(v[j - 1].second), used.insert(v[j - 1].second);
}
int main() {
  cin >> n;
  weapon = armor = orb = "";
  Size.clear();
  atk.clear();
  def.clear();
  res.clear();
  Kind.clear();
  Left.clear();
  used.clear();
  M.clear();
  for (int i = 1; i <= n; i++) {
    string Name, Type;
    int Atk, Def, Res, size;
    cin >> Name >> Type >> Atk >> Def >> Res >> size;
    atk[Name] = Atk;
    def[Name] = Def;
    res[Name] = Res;
    Size[Name] = size;
    Kind[Name] = Type;
    Left[Name] = size;
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> C[i] >> Tp[i] >> Bonus[i] >> Home[i];
    Left[Home[i]]--;
  }
  Flag = 0;
  for (map<string, int>::iterator i = Left.begin(); i != Left.end(); i++)
    if (i->second) Flag = 1;
  if (!Flag) {
    Sp();
    return 0;
  }
  work(weapon, "weapon", "gladiator");
  work(armor, "armor", "sentry");
  work(orb, "orb", "physician");
  cout << weapon << " ";
  doit(weapon);
  cout << armor << " ";
  doit(armor);
  cout << orb << " ";
  doit(orb);
  return 0;
}
