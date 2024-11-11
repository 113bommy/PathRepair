#include <bits/stdc++.h>
using namespace std;
const int maxn = 101000;
map<string, int> m;
map<string, int> match;
struct team {
  string name;
  int point, gscored, gconceded, gdiff;
  team(string tname) {
    name = tname;
    point = gscored = gconceded = gdiff = 0;
  }
  bool operator<(const team& t) const {
    if (point != t.point) return point > t.point;
    if (gscored - gconceded != t.gscored - t.gconceded)
      return gscored - gconceded > t.gscored - t.gconceded;
    if (gscored != t.gscored) return gscored > t.gscored;
    return name > t.name;
  }
};
vector<team> before;
vector<team> after;
void solve() {
  for (int i = 0; i < before.size(); i++) {
    after.push_back(before[i]);
  }
  sort(after.begin(), after.end());
  int berland = m["BERLAND"];
  int point = before[berland].point;
  if (point + 3 < after[1].point) {
    cout << "IMPOSSIBLE";
    return;
  }
  int opp = 0;
  for (int i = 0; i < before.size(); i++) {
    if (before[i].name != "BERLAND" && match[before[i].name] < 3) {
      opp = i;
    }
  }
  for (int gdiff = 1; gdiff < 300; gdiff++) {
    for (int X = gdiff; X < 300; X++) {
      int Y = X - gdiff;
      after.clear();
      for (int i = 0; i < before.size(); i++) {
        after.push_back(before[i]);
      }
      after[berland].point += 3;
      after[berland].gscored += X;
      after[berland].gconceded += Y;
      after[opp].gscored += Y;
      after[opp].gconceded += X;
      sort(after.begin(), after.end());
      if (after[0].name == "BERLAND" || after[1].name == "BERLAND") {
        cout << X << ":" << Y;
        return;
      }
    }
  }
}
int main() {
  cin.sync_with_stdio(false);
  string t1, t2;
  char ch1, tchar, ch2;
  for (int i = 0; i < 5; i++) {
    cin >> t1 >> t2 >> ch1 >> tchar >> ch2;
    if (match.count(t1) <= 0) {
      match[t1] = 1;
    } else
      match[t1] = match[t1] + 1;
    if (match.count(t2) <= 0) {
      match[t2] = 1;
    } else
      match[t2] = match[t2] + 1;
    if (m.count(t1) <= 0) {
      before.push_back(team(t1));
      m[t1] = before.size() - 1;
    }
    if (m.count(t2) <= 0) {
      before.push_back(team(t2));
      m[t2] = before.size() - 1;
    }
    int i1 = m[t1];
    int i2 = m[t2];
    if (ch1 > ch2) {
      before[i1].point += 3;
    } else if (ch2 > ch1) {
      before[i2].point += 3;
    } else {
      before[i1].point += 1;
      before[i2].point += 1;
    }
    before[i1].gscored += int(ch1) - '0';
    before[i1].gconceded += int(ch2) - '0';
    before[i2].gscored += int(ch2) - '0';
    before[i2].gconceded += int(ch1) - '0';
  }
  solve();
  return 0;
}
