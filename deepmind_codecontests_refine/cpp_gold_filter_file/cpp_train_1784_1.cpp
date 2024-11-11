#include <bits/stdc++.h>
using namespace std;
int m, n;
int res = INT_MAX;
vector<string> grid;
vector<string> ans;
string uu;
int u, v;
pair<char, char> rev = {'A', 'G'};
vector<char> cur = {'A', 'G', 'C', 'T'};
int change(string s, char u, char v) {
  int res = 0;
  for (int i = 0; i < (int)s.length(); i++) {
    if (s[i] != u && i % 2 == 0) res++;
    if (s[i] != v && i % 2) res++;
  }
  return res;
}
int main() {
  cin >> n >> m;
  grid.resize(n);
  ans.resize(n);
  for (int i = 0; i < n; i++) cin >> grid[i];
  vector<char> odd, eve;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j) continue;
      odd = {cur[i], cur[j]};
      eve.clear();
      for (int l = 0; l < 4; l++)
        if (l != i && l != j) eve.push_back(cur[l]);
      int aux = 0;
      for (int ii = 0; ii < n; ii++) {
        if (ii % 2)
          aux += min(change(grid[ii], odd[0], odd[1]),
                     change(grid[ii], odd[1], odd[0]));
        else
          aux += min(change(grid[ii], eve[0], eve[1]),
                     change(grid[ii], eve[1], eve[0]));
      }
      res = min(res, aux);
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j) continue;
      odd = {cur[i], cur[j]};
      eve.clear();
      for (int l = 0; l < 4; l++)
        if (cur[l] != cur[i] && cur[l] != cur[j]) eve.push_back(cur[l]);
      int aux = 0;
      for (int ii = 0; ii < m; ii++) {
        uu.clear();
        for (int jj = 0; jj < n; jj++) uu += grid[jj][ii];
        if (ii % 2)
          aux += min(change(uu, odd[0], odd[1]), change(uu, odd[1], odd[0]));
        else
          aux += min(change(uu, eve[0], eve[1]), change(uu, eve[1], eve[0]));
      }
      res = min(res, aux);
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j) continue;
      odd = {cur[i], cur[j]};
      eve.clear();
      for (int l = 0; l < 4; l++)
        if (l != i && l != j) eve.push_back(cur[l]);
      int aux = 0;
      for (int ii = 0; ii < n; ii++) {
        if (ii % 2)
          aux += min(change(grid[ii], odd[0], odd[1]),
                     change(grid[ii], odd[1], odd[0]));
        else
          aux += min(change(grid[ii], eve[0], eve[1]),
                     change(grid[ii], eve[1], eve[0]));
      }
      if (aux == res) {
        for (int ii = 0; ii < n; ii++) {
          if (ii % 2) {
            u = change(grid[ii], odd[0], odd[1]),
            v = change(grid[ii], odd[1], odd[0]);
            rev =
                (u > v ? make_pair(odd[1], odd[0]) : make_pair(odd[0], odd[1]));
            for (int jj = 0; jj < m; jj++) {
              if (jj % 2 == 0)
                ans[ii] += rev.first;
              else
                ans[ii] += rev.second;
            }
          }
          if (ii % 2 == 0) {
            u = change(grid[ii], eve[0], eve[1]),
            v = change(grid[ii], eve[1], eve[0]);
            rev =
                (u > v ? make_pair(eve[1], eve[0]) : make_pair(eve[0], eve[1]));
            for (int jj = 0; jj < m; jj++) {
              if (jj % 2 == 0)
                ans[ii] += rev.first;
              else
                ans[ii] += rev.second;
            }
          }
        }
        for (auto ll : ans) cout << ll << endl;
        return 0;
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j) continue;
      odd = {cur[i], cur[j]};
      eve.clear();
      for (int l = 0; l < 4; l++)
        if (cur[l] != cur[i] && cur[l] != cur[j]) eve.push_back(cur[l]);
      int aux = 0;
      for (int ii = 0; ii < m; ii++) {
        uu.clear();
        for (int jj = 0; jj < n; jj++) uu += grid[jj][ii];
        if (ii % 2)
          aux += min(change(uu, odd[0], odd[1]), change(uu, odd[1], odd[0]));
        else
          aux += min(change(uu, eve[0], eve[1]), change(uu, eve[1], eve[0]));
      }
      if (aux == res) {
        string lar;
        for (int ii = 0; ii < m; ii++) {
          lar.clear();
          for (int jj = 0; jj < n; jj++) lar += grid[jj][ii];
          if (ii % 2) {
            u = change(lar, odd[0], odd[1]), v = change(lar, odd[1], odd[0]);
            rev =
                (u > v ? make_pair(odd[1], odd[0]) : make_pair(odd[0], odd[1]));
            for (int jj = 0; jj < n; jj++) {
              if (jj % 2 == 0)
                ans[jj] += rev.first;
              else
                ans[jj] += rev.second;
            }
          } else {
            u = change(lar, eve[0], eve[1]), v = change(lar, eve[1], eve[0]);
            rev =
                (u > v ? make_pair(eve[1], eve[0]) : make_pair(eve[0], eve[1]));
            for (int jj = 0; jj < n; jj++) {
              if (jj % 2 == 0)
                ans[jj] += rev.first;
              else
                ans[jj] += rev.second;
            }
          }
        }
        for (auto ll : ans) cout << ll << endl;
        return 0;
      }
    }
  }
  return 0;
}
