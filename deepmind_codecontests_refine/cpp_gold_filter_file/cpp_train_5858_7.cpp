#include <bits/stdc++.h>
using namespace std;
string info[20005];
string rO(string a, int i) {
  if (i == -3) return "";
  if (i == -2) return "~";
  if (i == -1) return a;
  return a.substr(0, i) + a.substr(i + 1);
}
bool ccomp(array<int, 3> a, array<int, 3> b) {
  string a1, b1;
  a1 = rO(info[a[0]], a[1]);
  b1 = rO(info[b[0]], b[1]);
  return ((a1).compare(b1) < 0);
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> info[i];
  }
  vector<array<int, 3>> save;
  save.push_back({0, -3, 1});
  save.push_back({0, -2, 0});
  int next[20005];
  for (int i = 0; i < n; i++) {
    deque<array<int, 3>> start;
    deque<array<int, 3>> end;
    int wLen = info[i].length();
    next[wLen - 1] = wLen;
    for (int z = wLen - 2; z >= 0; z--) {
      if (info[i][z] != info[i][z + 1])
        next[z] = z + 1;
      else
        next[z] = next[z + 1];
    }
    for (int z = 0; z < wLen; z++) {
      if (next[z] == wLen || info[i][next[z]] < info[i][z]) {
        start.push_back({i, z, -1});
      } else {
        end.push_front({i, z, -1});
      }
    }
    vector<array<int, 3>> temp;
    for (auto a : start) {
      temp.push_back(a);
      if (a[1] == wLen - 1) temp.push_back({i, -1, -1});
    }
    for (auto a : end) {
      temp.push_back(a);
      if (a[1] == wLen - 1) temp.push_back({i, -1, -1});
    }
    vector<array<int, 3>> newS;
    int s = 0;
    auto it = save.begin();
    auto it1 = temp.begin();
    while (it1 != temp.end()) {
      array<int, 3> curr = (*it);
      array<int, 3> curr1 = (*it1);
      while (!ccomp(curr1, curr)) {
        s = (s + curr[2]) % 1000000007;
        curr = (*(++it));
      }
      newS.push_back({curr1[0], curr1[1], s});
      it1++;
    }
    newS.push_back({i, -2, 0});
    save = newS;
  }
  int ans = 0;
  for (auto a : save) {
    ans = (ans + a[2]) % 1000000007;
  }
  cout << ans << "\n";
}
