#include <bits/stdc++.h>
using namespace std;
int NUM = 0;
map<string, int> mas;
string names[10];
int get_num(string s) {
  map<string, int>::iterator iter = mas.find(s);
  if (iter == mas.end()) {
    mas[s] = NUM;
    names[NUM] = s;
    NUM++;
    return mas[s];
  }
  return iter->second;
}
struct tp {
  int g1, g2;
} sm[10][10];
int pl[10];
int root, o_root;
int N = 4;
struct tmm {
  int score, diff, zab;
  string name;
} ms[10];
bool operator<(const tmm &a, const tmm &b) {
  if (a.score > b.score) return true;
  if (a.score < b.score) return false;
  if (a.diff > b.diff) return true;
  if (a.diff < b.diff) return false;
  if (a.zab > b.zab) return true;
  if (a.zab < b.zab) return false;
  return a.name < b.name;
}
int calc_place() {
  for (int i = 0; i < N; i++) {
    ms[i].score = 0;
    ms[i].diff = 0;
    ms[i].zab = 0;
    ms[i].name = names[i];
    for (int j = 0; j < N; j++)
      if (j != i) {
        if (sm[i][j].g1 > sm[i][j].g2)
          ms[i].score += 3;
        else if (sm[i][j].g1 == sm[i][j].g2)
          ms[i].score += 1;
        ms[i].diff += sm[i][j].g1 - sm[i][j].g2;
        ms[i].zab += sm[i][j].g1;
      }
  }
  sort(ms, ms + N);
  for (int i = 0; i < N; i++)
    if (ms[i].name == "BERLAND") return i;
}
int main() {
  for (int i = 0; i < 5; i++) {
    string s1, s2, s3;
    int g1, g2;
    cin >> s1 >> s2 >> s3;
    sscanf(s3.c_str(), "%d:%d", &g1, &g2);
    int v1 = get_num(s1);
    int v2 = get_num(s2);
    sm[v1][v2].g1 = g1;
    sm[v1][v2].g2 = g2;
    sm[v2][v1].g1 = g2;
    sm[v2][v1].g2 = g1;
    if (s1 == "BERLAND") root = v1;
    if (s2 == "BERLAND") root = v2;
    pl[v1]++;
    pl[v2]++;
  }
  for (int i = 0; i < N; i++)
    if (pl[i] < 3 && i != root) o_root = i;
  int ans_x = -1, ans_y = -1;
  int mn = 1000000000;
  int mn_y = mn;
  int const MX = 500;
  for (int x = 0; x <= MX; x++)
    for (int y = 0; y <= MX; y++)
      if (x > y) {
        sm[root][o_root].g1 = x;
        sm[root][o_root].g2 = y;
        sm[o_root][root].g1 = y;
        sm[o_root][root].g2 = x;
        int P = calc_place();
        if (P <= 1) {
          if (x - y < mn || (x - y == mn && y < mn_y)) {
            mn = x - y;
            ans_x = x;
            ans_y = y;
            mn_y = y;
          }
        }
      }
  if (ans_x == -1)
    printf("IMPOSSIBLE");
  else
    printf("%d:%d", ans_x, ans_y);
  return 0;
}
