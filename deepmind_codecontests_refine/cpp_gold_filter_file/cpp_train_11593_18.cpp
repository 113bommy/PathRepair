#include <bits/stdc++.h>
using namespace std;
class team {
 public:
  string name;
  int win, lose, pnt;
  bool operator==(const team& t) {
    return (name == t.name && win == t.win && lose == t.lose && pnt == t.pnt);
  }
  void clear() {
    name = "";
    win = lose = pnt = 0;
  }
};
bool operator>(const team& tt, const team& t) {
  if (tt.pnt != t.pnt) return (tt.pnt > t.pnt);
  if (tt.win - tt.lose != t.win - t.lose)
    return (tt.win - tt.lose > t.win - t.lose);
  if (tt.win != t.win) return (tt.win > t.win);
  return tt.name <= t.name;
}
bool operator<(const team& tt, const team& t) {
  if (tt.pnt != t.pnt) return (tt.pnt < t.pnt);
  if (tt.win - tt.lose != t.win - t.lose)
    return (tt.win - tt.lose < t.win - t.lose);
  if (tt.win != t.win) return (tt.win < t.win);
  return tt.name <= t.name;
}
team make_team(const string& name, const int& win, const int& lose,
               const int& pnt) {
  team nt;
  nt.clear();
  nt.name = name;
  nt.win = win;
  nt.lose = lose;
  nt.pnt = pnt;
  return nt;
}
vector<team> v;
map<string, int> m;
int fin(const string& t) {
  int i;
  for (i = 0; i < v.size(); i++)
    if (v[i].name == t) return i;
  return -1;
}
pair<int, int> make_sc(const string& score) {
  int i = 0, sc1 = 0, sc2 = 0;
  while (i < score.size() && score[i] != ':')
    sc1 = sc1 * 10 + (score[i] - '0'), i++;
  i++;
  while (i < score.size()) sc2 = sc2 * 10 + (score[i] - '0'), i++;
  return make_pair(sc1, sc2);
}
void print() {
  for (int i = 0; i < v.size(); i++) printf("%s\n", v[i].name.c_str());
}
void add(const string& n1, const string& n2, const string& score) {
  if (false) cout << n1 << " " << n2 << " " << score << endl;
  int pos = fin(n1);
  pair<int, int> sc = make_sc(score);
  if (pos == -1) {
    team t;
    t.clear();
    t.win = sc.first;
    t.lose = sc.second;
    t.name = n1;
    t.pnt = (sc.first == sc.second ? 1 : (sc.first > sc.second ? 3 : 0));
    v.push_back(t);
    m[t.name] = 1;
  } else {
    m[v[pos].name]++;
    v[pos].win += sc.first;
    v[pos].lose += sc.second;
    v[pos].pnt += (sc.first == sc.second ? 1 : (sc.first > sc.second ? 3 : 0));
  }
  swap(sc.first, sc.second);
  pos = fin(n2);
  if (pos == -1) {
    team t;
    t.clear();
    t.win = sc.first;
    t.lose = sc.second;
    t.name = n2;
    t.pnt = (sc.first == sc.second ? 1 : (sc.first > sc.second ? 3 : 0));
    v.push_back(t);
    m[t.name]++;
  } else {
    m[v[pos].name]++;
    v[pos].win += sc.first;
    v[pos].lose += sc.second;
    v[pos].pnt += (sc.first == sc.second ? 1 : (sc.first > sc.second ? 3 : 0));
  }
}
bool cmp(const team& t1, const team& t2) { return (t1 > t2); }
void cop(vector<team>& v1, const vector<team>& v2) {
  v1.clear();
  for (int i = 0; i < v2.size(); i++) v1.push_back(v2[i]);
}
string tos(int a, int b) {
  string ans = "";
  char aa[50] = {};
  sprintf(aa, "%d:%d", a, b);
  ans = aa;
  return ans;
}
int main() {
  for (int i = 0; i < 5; i++) {
    string name1, name2, score;
    cin >> name1 >> name2 >> score;
    add(name1, name2, score);
  }
  sort(v.begin(), v.end(), cmp);
  if (false)
    for (int i = 0; i < v.size(); i++)
      printf("%d %s:WIN: %d, LOSE: %d, POINT: %d\n", i + 1, v[i].name.c_str(),
             v[i].win, v[i].lose, v[i].pnt);
  int bpos = fin("BERLAND");
  if (v[bpos].pnt + 3 < v[1].pnt) {
    puts("IMPOSSIBLE");
    return 0;
  }
  string oname = "";
  for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
    if (it->second == 2 && it->first != "BERLAND") oname = it->first;
  }
  int opos = fin(oname);
  int los = 0, cha = 1;
  for (; cha <= 100; cha++) {
    for (los = 0; los <= 100; los++) {
      vector<team> vt;
      cop(vt, v);
      add("BERLAND", oname, tos(los + cha, los));
      sort(v.begin(), v.end(), cmp);
      bpos = fin("BERLAND");
      if (bpos == 0 || bpos == 1) {
        printf("%d:%d\n", los + cha, los);
        return 0;
      }
      cop(v, vt);
    }
  }
  puts("IMPOSSIBLE");
  return 0;
}
