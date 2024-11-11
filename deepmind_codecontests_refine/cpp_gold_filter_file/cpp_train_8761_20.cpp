#include <bits/stdc++.h>
using namespace std;
int n;
int k;
char buf[100002];
string s;
int pf[100002];
int sf[100002];
vector<int> v;
vector<int> pos[2];
bool modify(int lef, int rig, int col) {
  int id = lower_bound(pos[col ^ 1].begin(), pos[col ^ 1].end(), lef) -
           pos[col ^ 1].begin();
  int id2 = upper_bound(pos[col ^ 1].begin(), pos[col ^ 1].end(), rig) -
            pos[col ^ 1].begin();
  id2--;
  if (id <= id2) {
    if (pos[col ^ 1][id2] - pos[col ^ 1][id] + 1 <= k) {
      return true;
    }
    return false;
  } else {
    return true;
  }
}
int main() {
  cin >> n >> k;
  if (n == k) {
    puts("tokitsukaze");
    return 0;
  }
  scanf("%s", buf);
  s = buf;
  for (int i = 0; i < s.size(); i++) {
    v.push_back(s[i] - '0');
    pos[v.back()].push_back(i);
  }
  int cur = v[0];
  for (int i = 0; i < s.size(); i++) {
    if (cur == v[i]) {
      cur = v[i];
    } else {
      cur = -1;
    }
    pf[i] = cur;
  }
  cur = v.back();
  for (int i = s.size() - 1; i >= 0; i--) {
    if (cur == v[i]) {
      cur = v[i];
    } else {
      cur = -1;
    }
    sf[i] = cur;
  }
  for (int i = 0; i + k <= s.size(); i++) {
    if (i && pf[i - 1] == -1) break;
    if (i == 0) {
      if (sf[i + k] != -1) {
        puts("tokitsukaze");
        return 0;
      }
      continue;
    }
    if (i + k == s.size() || sf[i + k] == pf[i - 1]) {
      puts("tokitsukaze");
      return 0;
    }
  }
  for (int i = 0; i + k <= s.size(); i++) {
    for (int j = 0; j < 2; j++) {
      bool side1 = false;
      bool side2 = false;
      if (i == 0 || pf[i - 1] == j) {
        side1 = false;
      } else {
        side1 = true;
      }
      if (i + k == s.size() || sf[i + k] == j) {
      } else {
        side2 = true;
      }
      if (side1 && side2) {
        puts("once again");
        return 0;
      }
      if (side1 == false && side2 == false) continue;
      if (side1 == true) {
        if (modify(0, i - 1, j))
          continue;
        else {
          puts("once again");
          return 0;
        }
      }
      if (side2 == true) {
        if (modify(i + k, n - 1, j)) continue;
        puts("once again");
        return 0;
      }
    }
  }
  puts("quailty");
  return 0;
}
