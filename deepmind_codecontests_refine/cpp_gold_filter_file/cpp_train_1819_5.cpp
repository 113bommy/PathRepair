#include <bits/stdc++.h>
using namespace std;
int pw(int a, int b) {
  int ans = 1;
  while (b > 0) {
    ans *= a;
    b--;
  }
  return ans;
}
int zap(string &sc, int &c, string sp, int p) {
  if (sc.size() > sp.size()) return -1;
  c = 0;
  if (sc.size() < sp.size()) {
    for (int j = 0; j < sc.size(); j++) {
      c *= 10;
      if (sc[j] != '?') continue;
      sc[j] = '9';
      c += sc[j] - '0';
    }
    return 0;
  }
  if (sc.size() == sp.size()) {
    int pol = -1;
    bool ravnev = true;
    for (int j = 0; j < sc.size(); j++) {
      if (sc[j] == '?') continue;
      if (sc[j] != sp[j]) {
        pol = j;
        ravnev = false;
        break;
      }
    }
    bool per = false;
    if (ravnev) {
      pol = -1;
      for (int j = (int)sc.size() - 1; j >= 0; j--) {
        if (sc[j] == '?' && sp[j] != '0') {
          pol = j;
          break;
        }
      }
      if (pol == -1) {
        return -1;
      }
      for (int j = (int)sc.size() - 1; j >= 0; j--) {
        if (sc[j] == '?') {
          if (j < pol) {
            sc[j] = sp[j];
          } else if (j == pol) {
            if (j == 0 && sp[j] == '1') return -1;
            sc[j] = sp[j] - 1;
          } else {
            sc[j] = '9';
          }
        } else {
          if (!per) {
            if (sp[j] - '0' < sc[j] - '0') {
              return -1;
            }
          }
        }
        if (sp[j] - '0' > sc[j] - '0') {
          per = true;
        }
      }
    } else {
      if (sp[pol] - '0' > sc[pol] - '0') {
        for (int j = 0; j < sc.size(); j++) {
          if (sc[j] == '?') {
            if (j < pol) {
              sc[j] = sp[j];
            } else {
              sc[j] = '9';
            }
          } else {
            if (!per) {
              if (sp[j] - '0' < sc[j] - '0') {
                return -1;
              }
            }
          }
          if (sp[j] - '0' > sc[j] - '0') {
            per = true;
          }
        }
      } else {
        int pol2 = -1;
        for (int j = pol - 1; j >= 0; j--) {
          if (sc[j] == '?' && sp[j] != '0') {
            pol2 = j;
            break;
          }
        }
        if (pol2 == -1) {
          return -1;
        }
        for (int j = 0; j < sc.size(); j++) {
          if (sc[j] == '?') {
            if (j < pol2) {
              sc[j] = sp[j];
            } else if (j == pol2) {
              sc[j] = sp[j] - 1;
            } else {
              sc[j] = '9';
            }
          }
        }
      }
    }
    return 0;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  string symb[n];
  for (int i = 0; i < n; i++) {
    cin >> symb[i];
  }
  int num[n];
  int prev = 100 * 1000 * 1000, t;
  num[n - 1] = 0;
  for (int j = 0; j < symb[n - 1].size(); j++) {
    num[n - 1] *= 10;
    if (symb[n - 1][j] != '?') {
      num[n - 1] += symb[n - 1][j] - '0';
      continue;
    }
    symb[n - 1][j] = '9';
    num[n - 1] += symb[n - 1][j] - '0';
  }
  for (int i = n - 2; i >= 0; i--) {
    if (zap(symb[i], num[i], symb[i + 1], num[i + 1]) == -1) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    cout << symb[i] << '\n';
  }
  return 0;
}
