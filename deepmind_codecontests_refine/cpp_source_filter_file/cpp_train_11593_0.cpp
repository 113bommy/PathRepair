#include <bits/stdc++.h>
using namespace std;
struct team {
  string name;
  int score, goal, miss;
  int cnt;
  team(string n = "") {
    name = n;
    score = goal = miss = cnt = 0;
  }
  bool operator<(const team &t2) const {
    if (score > t2.score) return true;
    if (score < t2.score) return false;
    int c1 = goal - miss, c2 = t2.goal - t2.miss;
    if (c1 > c2) return true;
    if (c1 < c2) return false;
    if (goal > t2.goal) return true;
    if (goal < t2.goal) return false;
    return (name < t2.name);
  }
};
team tms[4];
map<string, int> mp;
void add(int k1, int k2, int g1, int g2, int c) {
  if (g1 > g2)
    tms[k1].score += (c * 3);
  else if (g2 > g1)
    tms[k2].score += (c * 3);
  else {
    tms[k1].score += c;
    tms[k2].score += c;
  }
  tms[k1].goal += (c * g1);
  tms[k2].goal += (c * g2);
  tms[k1].miss += (c * g2);
  tms[k2].miss += (c * g1);
  tms[k1].cnt += c;
  tms[k1].cnt += c;
}
bool test(int k, int x, int y) {
  add(0, k, x, y, 1);
  int p = 0;
  for (int i = 1; i < 4; i++)
    if (tms[i] < tms[0]) p++;
  if (p < 2)
    p = 1;
  else
    p = 0;
  add(0, k, x, y, -1);
  return p;
}
int main() {
  string t1, t2, res;
  int k = 1;
  tms[0] = team("BERLAND");
  mp["BERLAND"] = 0;
  for (int i = 0; i < 5; i++) {
    cin >> t1 >> t2 >> res;
    if (mp.find(t1) == mp.end()) {
      tms[k] = team(t1);
      mp[t1] = k++;
    }
    if (mp.find(t2) == mp.end()) {
      tms[k] = team(t2);
      mp[t2] = k++;
    }
    add(mp[t1], mp[t2], res[0] - '0', res[2] - '0', 1);
  }
  for (int i = 1; i < 4; i++) {
    if (tms[i].cnt == 2) k = i;
  }
  int a1 = 100, a2 = 0;
  for (int x = 0; x < 30; x++) {
    for (int y = 0; y < x; y++) {
      if (test(k, x, y)) {
        if (x - y < a1 - a2) {
          a1 = x;
          a2 = y;
        } else if (x - y > a1 - a2)
          continue;
        else if (y < a2) {
          a1 = x;
          a2 = y;
        }
      }
    }
  }
  if (a1 == 100)
    cout << "IMPOSSIBLE" << endl;
  else
    cout << a1 << ":" << a2 << endl;
}
