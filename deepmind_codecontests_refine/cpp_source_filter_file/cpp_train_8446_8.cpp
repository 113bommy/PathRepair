#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 20;
char buff[MAX];
pair<int, int> check(string &s) {
  if (s.size() >= 4) {
    if (s.substr(s.size() - 4, 4) == "lios") return {1, 1};
  }
  if (s.size() >= 5) {
    if (s.substr(s.size() - 5, 5) == "liala") return {1, 2};
  }
  if (s.size() >= 3) {
    if (s.substr(s.size() - 3, 3) == "etr") return {2, 1};
  }
  if (s.size() >= 4) {
    if (s.substr(s.size() - 4, 4) == "etra") return {2, 2};
  }
  if (s.size() >= 6) {
    if (s.substr(s.size() - 6, 6) == "initis") return {3, 1};
  }
  if (s.size() >= 6) {
    if (s.substr(s.size() - 6, 6) == "inites") return {3, 2};
  }
  return {-1, -1};
}
int main() {
  cin.getline(buff, 255, '\n');
  int len = strlen(buff);
  int i = 0;
  vector<string> ss;
  while (i < len) {
    int j = i;
    while (j < len && buff[j] != ' ') j++;
    ss.push_back(string(buff, i, j - i));
    i = j + 1;
  }
  struct node {
    int ty;
    int fe;
    node(int a = 0, int b = 0) : ty(a), fe(b) {}
  };
  vector<node> hh;
  bool ok = 1;
  int ns = 0, id;
  pair<int, int> re;
  for (int i = 0; i < ss.size(); i++) {
    auto ele = check(ss[i]);
    hh.push_back({ele.first, ele.second});
    if (ele.first == -1) {
      ok = 0;
      break;
    }
    if (ele.first == 2) ns++, re = ele, id = i;
  }
  if (ok && ss.size() == 1) {
    printf("YES\n");
    return 0;
  }
  if (!ok)
    printf("NO\n");
  else {
    if (ns != 1)
      printf("NO\n");
    else {
      int fe = re.second;
      for (int i = 0; i < id; i++) {
        if (hh[i].ty != 1 || hh[i].fe != fe) {
          ok = 0;
          break;
        }
      }
      if (!ok)
        printf("NO\n");
      else {
        for (int i = id + 1; i < hh.size(); i++) {
          if (hh[i].ty != 3 || hh[i].fe != fe) {
            ok = 0;
            break;
          }
        }
        if (!ok)
          printf("NO\n");
        else
          printf("YES\n");
      }
    }
  }
  return 0;
}
