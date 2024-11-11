#include <bits/stdc++.h>
using namespace std;
int n, m;
int ans[200514];
set<int> cl[200514], ocl[200514], voc[2][200514];
int check() {
  for (int i = 0; i < (n); i++) {
    int f1 = 0;
    for (auto it : ocl[i]) {
      int t = abs(it);
      f1 |= (it > 0 && ans[t] == 1);
      f1 |= (it < 0 && ans[t] == 0);
    }
    if (f1 == 0) return 0;
  }
  return 1;
}
int fuck(int i, int c) { return cl[c].count(i) ? 1 : 0; }
vector<int> vtc[200514];
void del(int it, int c) {
  if (((int)vtc[it].size()) <= 1) {
    vtc[it].clear();
    return;
  }
  if (vtc[it][0] == c) {
    vtc[it][0] = vtc[it][1];
  }
  vtc[it].pop_back();
}
void kiill(int c) {
  for (auto it : cl[c]) {
    del(abs(it), c);
  }
  cl[c].clear();
}
int sol(int uuu) {
  for (int i = 0; i < (n); i++) cl[i].clear();
  for (int i = 0; i < (m); i++) vtc[i + 1].clear();
  for (int i = 0; i < (n); i++) {
    int tn;
    scanf("%d", &(tn));
    for (int j = 0; j < (tn); j++) {
      int x;
      scanf("%d", &(x));
      cl[i].insert(x);
      vtc[abs(x)].push_back(i);
    }
    ocl[i] = cl[i];
  }
  for (int i = 0; i < (m); i++) ans[i + 1] = -1;
  for (int i = 0; i < (m + 1); i++)
    if (i) {
      if (((int)vtc[i].size()) == 0) {
        ans[i] = 0;
        continue;
      }
      if (((int)vtc[i].size()) == 1) {
        ans[i] = fuck(i, vtc[i][0]);
        kiill(vtc[i][0]);
        continue;
      }
      if (fuck(i, vtc[i][0]) == fuck(i, vtc[i][1])) {
        ans[i] = fuck(i, vtc[i][0]);
        kiill(vtc[i].back());
        kiill(vtc[i].back());
        continue;
      }
      ans[i] = -1;
      int bm = ((int)cl[vtc[i][0]].size()) < ((int)cl[vtc[i][1]].size())
                   ? vtc[i][0]
                   : vtc[i][1];
      int am = vtc[i][0] + vtc[i][1] - bm;
      if (fuck(i, vtc[i][0]) == 0) {
        if (bm == vtc[i][0])
          voc[0][i] = cl[vtc[i][0]];
        else
          voc[1][i] = cl[vtc[i][1]];
      } else {
        if (bm == vtc[i][1])
          voc[0][i] = cl[vtc[i][1]];
        else
          voc[1][i] = cl[vtc[i][0]];
      }
      cl[am].erase(+i);
      cl[am].erase(-i);
      cl[bm].erase(+i);
      cl[bm].erase(-i);
      for (auto it : cl[bm]) {
        int t = abs(it);
        del(t, bm);
        if (((int)vtc[t].size()) && vtc[t][0] == am) {
          ;
          ;
          ;
          ;
          ;
          ;
          ;
          ;
          ;
          ;
        } else {
          vtc[t].push_back(am);
        }
      }
      cl[am].insert((cl[bm]).begin(), (cl[bm]).end());
      cl[bm].clear();
      vtc[i].clear();
    }
  for (int i = m; i >= 1; i--) {
    if (ans[i] == 7122) {
      puts("NO");
      return 1;
    }
    if (ans[i] != -1) continue;
    int f1 = 0;
    int cr = ((int)voc[0][i].size()) ? 0 : 1;
    for (auto it : voc[cr][i]) {
      int t = abs(it);
      f1 |= (it > 0 && ans[t] == 1);
      f1 |= (it < 0 && ans[t] == 0);
    }
    ans[i] = f1 ^ cr;
  }
  if (check()) {
    puts("YES");
    for (int i = 0; i < (m); i++) printf("%d", ans[i + 1]);
    puts("");
  } else {
    puts("NO");
  }
  return 1;
}
int main() {
  while (scanf("%d %d", &(n), &(m)) != EOF) sol(0);
  return 0;
}
