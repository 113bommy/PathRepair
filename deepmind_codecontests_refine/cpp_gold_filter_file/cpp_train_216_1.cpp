#include <bits/stdc++.h>
using namespace std;
void prepare() {}
struct P {
  string name, cl;
  int type, atk, def, res, size, num;
  void read() {
    cin >> name >> cl;
    cin >> atk >> def >> res >> size;
    if (cl == "weapon")
      type = 0;
    else if (cl == "armor")
      type = 1;
    else if (cl == "orb")
      type = 2;
    else
      assert(false);
  }
};
struct R {
  string name, cl, home;
  int type, bonus, num;
  bool operator<(const R &v) const { return bonus > v.bonus; }
  void read() {
    cin >> name >> cl >> bonus >> home;
    if (cl == "gladiator")
      type = 0;
    else if (cl == "sentry")
      type = 1;
    else if (cl == "physician")
      type = 2;
    else
      assert(false);
  }
};
int n, m;
vector<P> p[3];
vector<R> r[3], v[3];
vector<int> sum[3];
vector<bool> used[3];
int all_size, all_res;
map<string, vector<R> > ma;
map<string, int> sma[3];
map<string, int> tt;
bool ms(const P &a, const P &b) {
  return sma[a.type][a.name] > sma[b.type][b.name];
}
void solve() {
  cin >> n;
  P e;
  for (int i = (0); i < (((n))); i++) {
    e.read();
    p[e.type].push_back(e);
    all_size += e.size;
    tt[e.name] = e.type;
    if (e.type == 0)
      sma[e.type][e.name] = e.atk;
    else if (e.type == 1)
      sma[e.type][e.name] = e.def;
    else
      sma[e.type][e.name] = e.res;
  }
  cin >> m;
  R f;
  for (int i = (0); i < (((m))); i++) {
    f.read();
    r[f.type].push_back(f);
    all_res++;
    ma[f.home].push_back(f);
    if (tt[f.home] == f.type)
      sma[f.type][f.home] = sma[f.type][f.home] + f.bonus;
  }
  if (all_size == all_res) {
    for (int i = (0); i < (((3))); i++) sort((p[i]).begin(), (p[i]).end(), ms);
    for (int i = (0); i < (((3))); i++) {
      string name = p[i][0].name;
      printf("%s %d", name.c_str(), (int)(ma[name]).size());
      for (vector<R>::iterator it = ma[name].begin(); it != ma[name].end();
           ++it)
        printf(" %s", it->name.c_str());
      printf("\n");
    }
    return;
  }
  for (int i = (0); i < (((3))); i++) {
    if ((int)(r[i]).size()) {
      sort((r[i]).begin(), (r[i]).end());
      sum[i].push_back(r[i][0].bonus);
      for (int j = (1); j < ((int)(r[i]).size()); j++)
        sum[i].push_back(sum[i].back() + r[i][j].bonus);
      for (int j = (0); j < ((((int)(r[i]).size()))); j++)
        used[i].push_back(false);
    }
  }
  int res_cnt[3], res_p[3], cur_cnt[3];
  res_cnt[0] = -1;
  res_cnt[1] = -1;
  res_cnt[2] = -1;
  for (int i = (0); i < ((((int)(p[0]).size()))); i++) {
    if ((int)(sum[0]).size())
      cur_cnt[0] =
          p[0][i].atk + sum[0][min((int)(sum[0]).size() - 1, p[0][i].size - 1)];
    else
      cur_cnt[0] = p[0][i].atk;
    if (cur_cnt[0] < res_cnt[0]) continue;
    for (int j = (0); j < ((((int)(p[1]).size()))); j++) {
      if ((int)(sum[1]).size())
        cur_cnt[1] = p[1][j].def +
                     sum[1][min((int)(sum[1]).size() - 1, p[1][j].size - 1)];
      else
        cur_cnt[1] = p[1][j].def;
      if (cur_cnt[0] == res_cnt[0] && cur_cnt[1] < res_cnt[1]) continue;
      for (int k = (0); k < ((int)(p[2]).size()); k++) {
        if ((int)(sum[2]).size())
          cur_cnt[2] = p[2][k].res +
                       sum[2][min((int)(sum[2]).size() - 1, p[2][k].size - 1)];
        else
          cur_cnt[2] = p[2][k].res;
        if (cur_cnt[0] == res_cnt[0] && cur_cnt[1] == res_cnt[1] &&
            cur_cnt[2] < res_cnt[2])
          continue;
        res_cnt[0] = cur_cnt[0];
        res_cnt[1] = cur_cnt[1];
        res_cnt[2] = cur_cnt[2];
        res_p[0] = i;
        res_p[1] = j;
        res_p[2] = k;
      }
    }
  }
  for (int i = (0); i < (((3))); i++) {
    for (int j = (0); j < (((min((int)(r[i]).size(), p[i][res_p[i]].size))));
         j++) {
      v[i].push_back(r[i][j]);
      used[i][j] = true;
    }
  }
  for (int k = (0); k < (3); k++) {
    for (int i = (0); i < (((3))); i++) {
      if ((int)(v[k]).size() >= p[k][res_p[k]].size) break;
      for (int j = (0); j < ((((int)(r[i]).size()))); j++) {
        if ((int)(v[k]).size() >= p[k][res_p[k]].size) break;
        if (!used[i][j]) {
          used[i][j] = true;
          v[k].push_back(r[i][j]);
        }
      }
    }
  }
  for (int i = (0); i < (((3))); i++) {
    printf("%s %d", p[i][res_p[i]].name.c_str(), (int)(v[i]).size());
    for (int j = (0); j < ((((int)(v[i]).size()))); j++)
      printf(" %s", v[i][j].name.c_str());
    printf("\n");
  }
}
int main() {
  prepare();
  solve();
  return 0;
}
