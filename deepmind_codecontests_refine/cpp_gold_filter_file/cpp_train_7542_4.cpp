#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:666000000")
using namespace std;
const int inf = (1 << 30) - 1;
const long double eps = 1e-9;
const long double pi = fabs(atan2(0.0, -1.0));
void ML(const bool v) {
  if (v) return;
  int *ass;
  for (;;) {
    ass = new int[2500000];
    for (int i = 0; i < 2500000; i++) ass[i] = rand();
  }
}
void TL(const bool v) {
  if (v) return;
  int *ass;
  ass = new int[250];
  for (;;) {
    for (int i = 0; i < 250; i++) ass[i] = rand();
  }
}
void PE(const bool v) {
  if (v) return;
  puts("ass 1 2 3 4 5 6 fuck");
  exit(0);
}
vector<string> s;
void LoAd() {
  s.resize(6);
  for (int i = 0; i < 6; i++) cin >> s[i];
}
vector<string> bres;
vector<string> res;
map<vector<string>::iterator, bool> used;
vector<vector<char>> was;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
void dfs(const int x, const int y) {
  if (x < 0 || y < 0 || x >= (int)res.size() || y >= res[0].size()) return;
  if ('.' != res[x][y]) return;
  if (was[x][y]) return;
  was[x][y] = true;
  for (int i = 0; i < 4; i++) dfs(x + dx[i], y + dy[i]);
}
void SoLvE() {
  for (auto it = s.begin(); it != s.end(); it++) used[it] = false;
  for (auto su = s.begin(); su != s.end(); su++) {
    used[su] = true;
    for (auto sl = s.begin(); sl != s.end(); sl++)
      if ((*sl)[0] == (*su)[0] && !used[sl]) {
        used[sl] = true;
        for (auto sv = s.begin(); sv != s.end(); sv++)
          if (sv->front() == su->back() && sv->size() > sl->size() &&
              !used[sv]) {
            used[sv] = true;
            for (auto sd = s.begin(); sd != s.end(); sd++)
              if (sd->front() == sv->back() && !used[sd]) {
                used[sd] = true;
                for (auto sr = s.begin(); sr != s.end(); sr++)
                  if (sr->back() == sd->back() &&
                      (sl->size() + sr->size()) == (sv->size() + 1) &&
                      !used[sr]) {
                    used[sr] = true;
                    for (auto sh = s.begin(); sh != s.end(); sh++)
                      if (sh->front() == sl->back() &&
                          sh->back() == sr->front() && !used[sh]) {
                        int ii = sl->size() - 1;
                        int jj = su->size() - 1;
                        if (su->size() + sd->size() == sh->size() + 1 &&
                            (*sv)[ii] == (*sh)[jj]) {
                          res.clear();
                          res.assign(sv->size(), string(sh->size(), '.'));
                          for (int j = 0; j < (int)sh->size(); j++)
                            res[ii][j] = (*sh)[j];
                          for (int i = 0; i < (int)sv->size(); i++)
                            res[i][su->size() - 1] = (*sv)[i];
                          for (int i = 0; i < (int)sd->size(); i++)
                            res[sv->size() - 1][su->size() - 1 + i] = (*sd)[i];
                          for (int i = 0; i < (int)su->size(); i++)
                            res[0][i] = (*su)[i];
                          for (int i = 0; i < (int)sl->size(); i++)
                            res[i][0] = (*sl)[i];
                          for (int i = 0; i < (int)sr->size(); i++)
                            res[sv->size() - sr->size() + i]
                               [su->size() + sd->size() - 2] = (*sr)[i];
                          was.clear();
                          was.assign(res.size(),
                                     vector<char>(res[0].size(), false));
                          int cnt = 0;
                          for (int i = 0; i < (int)res.size(); i++)
                            for (int j = 0; j < (int)res[i].size(); j++)
                              if ('.' == res[i][j] && !was[i][j]) {
                                cnt++;
                                dfs(i, j);
                              }
                          if (4 == cnt && (bres.empty() || res < bres))
                            bres = res;
                        }
                      }
                    used[sr] = false;
                  }
                used[sd] = false;
              }
            used[sv] = false;
          }
        used[sl] = false;
      }
    used[su] = false;
  }
  if (bres.empty()) {
    puts("Impossible");
    return;
  }
  for (int i = 0; i < (int)bres.size(); i++) cout << bres[i] << endl;
}
int main() {
  srand((int)time(NULL));
  LoAd();
  SoLvE();
  return 0;
}
