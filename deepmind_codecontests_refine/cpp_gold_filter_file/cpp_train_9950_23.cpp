#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e5 + 5;
const int sigma = 28;
string a, b;
int n, m;
int stanga[nmax][sigma], dreapta[nmax][sigma];
int prefixB[nmax], sufixB[nmax];
int getC(char c) { return c - 'a'; }
int getJ(int pos, int val) {
  int st = pos - 1;
  int dr = m + 1;
  while (dr - st > 1) {
    int mij = (st + dr) / 2;
    if (sufixB[mij] > val) {
      dr = mij;
    } else {
      st = mij;
    }
  }
  if (dr == m + 1) {
    return -1;
  }
  return dr;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> a >> b;
  n = a.size();
  m = b.size();
  for (int i = 1; i <= n; ++i) {
    for (int j = getC('a'); j <= getC('z'); ++j) {
      if (i == 1) {
        stanga[i][j] = 0;
      } else {
        stanga[i][j] = stanga[i - 1][j];
      }
    }
    int currC = getC(a[i - 1]);
    stanga[i][currC] = i;
  }
  for (int i = n; i >= 1; --i) {
    for (int j = getC('a'); j <= getC('z'); ++j) {
      if (i == n) {
        dreapta[i][j] = n + 1;
      } else {
        dreapta[i][j] = dreapta[i + 1][j];
      }
    }
    int currC = getC(a[i - 1]);
    dreapta[i][currC] = i;
  }
  prefixB[0] = 0;
  for (int i = 1; i <= m; ++i) {
    int currCPos = getC(b[i - 1]);
    int currPosInA = prefixB[i - 1] + 1;
    if (currPosInA > n) {
      prefixB[i] = n + 1;
      continue;
    }
    prefixB[i] = dreapta[currPosInA][currCPos];
  }
  sufixB[m + 1] = n + 1;
  for (int i = m; i >= 1; --i) {
    int currCPos = getC(b[i - 1]);
    int currPosInA = sufixB[i + 1] - 1;
    if (currPosInA <= 0) {
      sufixB[i] = 0;
      continue;
    }
    sufixB[i] = stanga[currPosInA][currCPos];
  }
  int ans = (1 << 30);
  pair<int, int> ansPair = make_pair(-1, -1);
  for (int i = 1; i <= m; ++i) {
    if (prefixB[i] <= n) {
      int curr = m - i;
      if (curr < ans) {
        ans = curr;
        ansPair = make_pair(i, m + 1);
      }
    }
    if (sufixB[i] > 0) {
      int curr = i - 1;
      if (curr < ans) {
        ans = curr;
        ansPair = make_pair(0, i);
      }
    }
    int j = getJ(i + 1, prefixB[i]);
    if (j == -1) {
      continue;
    } else {
      int curr = j - i - 1;
      if (curr < ans) {
        ans = curr;
        ansPair = make_pair(i, j);
      }
    }
  }
  string ansS = "";
  if (ansPair.first == -1) {
    cout << "-";
    return 0;
  }
  for (int i = 0; i < ansPair.first; ++i) {
    ansS += b[i];
  }
  for (int i = ansPair.second - 1; i < m; ++i) {
    ansS += b[i];
  }
  cout << ansS << "\n";
  return 0;
}
