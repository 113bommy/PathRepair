#include <bits/stdc++.h>
using namespace std;
struct word {
  char a[12];
};
short findInv(vector<pair<size_t, int> > &a, int &b) {
  int pos[5];
  for (int x = 0; x < 5; x++) pos[x] = 0;
  int arrSize = a.size();
  int n = b;
  int pos1, pos2;
  for (int x = 0; x < arrSize; x++) {
    if (a[x].second == 1) {
      pos1 = x + 1;
      break;
    }
  }
  for (int x = arrSize - 1; x > -1; x--) {
    if (a[x].second == n) {
      pos2 = x + 1;
      break;
    }
  }
  if (n == 1) {
    return 0;
  }
  if (n == 2) {
    if (pos1 > pos2)
      return 1;
    else
      return 0;
  }
  if (n == 3) {
    pos[1] = pos1;
    pos[n] = pos2;
    short res = 0;
    vector<short> p;
    for (int x = 0; x < arrSize; x++)
      if (a[x].second == 2) p.push_back(x + 1);
    bool isf = true;
    for (int x = 0; x < p.size(); x++) {
      pos[2] = p[x];
      short bingo = 0;
      for (int x = 1; x <= n; x++)
        for (int op = x + 1; op <= n; op++)
          if (pos[x] > pos[op]) bingo++;
      if (isf) {
        res = bingo;
        isf = false;
      } else {
        if (bingo < res) res = bingo;
      }
    }
    return res;
  }
  if (n == 4) {
    pos[1] = pos1;
    pos[n] = pos2;
    short res = 0;
    vector<short> p;
    vector<short> p1;
    for (int x = 0; x < arrSize; x++)
      if (a[x].second == 2) p.push_back(x + 1);
    for (int x = 0; x < arrSize; x++)
      if (a[x].second == 3) p1.push_back(x + 1);
    bool isf = true;
    for (int x = 0; x < p.size(); x++) {
      pos[2] = p[x];
      for (int o = 0; o < p1.size(); o++) {
        pos[3] = p1[o];
        short bingo = 0;
        for (int lupa = 1; lupa < n; lupa++)
          for (int op = lupa + 1; op <= n; op++)
            if (pos[lupa] > pos[op]) bingo++;
        if (isf) {
          res = bingo;
          isf = false;
        } else if (bingo < res) {
          res = bingo;
        }
      }
    }
    return res;
  }
}
int main() {
  int n, m;
  cin >> n;
  word h[n];
  vector<pair<short, short> > lo;
  for (int x = 0; x < n; x++) {
    cin >> h[x].a;
  }
  cin >> m;
  for (int u = 0; u < m; u++) {
    short po;
    vector<pair<size_t, int> > gama;
    cin >> po;
    word lama[po];
    for (int x = 0; x < po; x++) cin >> lama[x].a;
    short hGot = 0;
    for (int op = 0; op < n; op++) {
      bool isf = true;
      for (size_t lk = 0; lk < po; lk++) {
        if (strcmp(h[op].a, lama[lk].a) == 0) {
          if (isf) {
            hGot++;
            isf = false;
          }
          gama.push_back(make_pair(lk, op + 1));
        }
      }
    }
    if (gama.size() != 0 && hGot == n) {
      sort(gama.begin(), gama.end());
      short inv = findInv(gama, n);
      lo.push_back(make_pair(inv, u));
    }
  }
  if (lo.size() != 0) {
    sort(lo.begin(), lo.end());
    int poo = ((n * (n - 1)) / 2) + 1 - lo[0].first;
    cout << lo[0].second + 1 << endl;
    cout << "[:";
    for (int o = 0; o < poo; o++) cout << "|";
    cout << ":]";
  } else {
    cout << "Brand new problem!";
  }
}
