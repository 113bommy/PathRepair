#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
string s[31][1000];
int v[31][1000];
int nt[31];
struct person {
  string name;
  int num;
} p[31];
string a;
map<string, int> name;
map<string, int> num;
int main() {
  int n;
  cin >> n;
  int np = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (name[a] == 0) {
      np++;
      name[a] = np;
      p[np].name = a;
      p[np].num = 1;
    }
    int x = name[a];
    int t = 0;
    int T;
    cin >> T;
    for (int i1 = 0; i1 < T; i1++) {
      cin >> a;
      s[x][nt[x]] = a;
      nt[x]++;
      p[x].num = nt[x];
    }
  }
  for (int i = 1; i <= np; i++) {
    for (int j = 0; j < nt[i] - 1; j++) {
      for (int x1 = j + 1; x1 < nt[i]; x1++) {
        if (v[i][j] == 1 || v[i][x1] == 1) {
          continue;
        }
        int l1 = s[i][j].length();
        int l2 = s[i][x1].length();
        int judge = 0;
        if (l1 > l2) {
          int i2 = 0;
          for (int i1 = l1 - l2; i1 < l1; i1++, i2++) {
            if (s[i][j][i1] != s[i][x1][i2]) {
              break;
            } else if (i1 == l1 - 1) {
              judge = 1;
              v[i][x1] = 1;
              break;
            }
          }
        } else {
          int i2 = 0;
          for (int i1 = l2 - l1; i1 < l2; i1++, i2++) {
            if (s[i][x1][i1] != s[i][j][i2]) {
              break;
            } else if (i1 == l2 - 1) {
              v[i][j] = 1;
              judge = 1;
              break;
            }
          }
        }
        if (judge == 1) {
          p[i].num--;
        }
      }
    }
  }
  cout << np << '\n';
  for (int i = 1; i <= np; i++) {
    cout << p[i].name << " ";
    cout << p[i].num << " ";
    for (int j = 0; j < nt[i]; j++) {
      if (v[i][j] != 1) cout << s[i][j] << " ";
    }
    cout << "\n";
  }
}
