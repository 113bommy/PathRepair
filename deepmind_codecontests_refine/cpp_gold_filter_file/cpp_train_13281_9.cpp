#include <bits/stdc++.h>
using namespace std;
const int maxN = 100;
int d[maxN][maxN][maxN][3];
int arr[maxN];
int pos[3][maxN];
int pref[maxN][3];
void prec(int n) {
  int cnt[3] = {0, 0, 0};
  for (int i = 0; i < n; i++) {
    cnt[arr[i]]++;
    pos[arr[i]][cnt[arr[i]]] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      pref[i][j] = (i == 0) ? 0 : pref[i - 1][j];
      pref[i][j] += arr[i] == j;
    }
  }
}
int main(void) {
  string s;
  int n;
  cin >> n;
  cin >> s;
  for (int i = 0; i < (int)s.size(); i++) {
    arr[i] = s[i] == 'K' ? 0 : (s[i] == 'V' ? 1 : 2);
  }
  prec(n);
  int cnt[3] = {0, 0, 0};
  int& k = cnt[0];
  int& v = cnt[1];
  int& x = cnt[2];
  for (k = 0; k < n; k++) {
    for (v = 0; v < n; v++) {
      for (x = 0; x < n; x++) {
        if (k + v + x == 0) {
          d[k][v][x][0] = 1e9;
          d[k][v][x][1] = 1e9;
          d[v][v][x][2] = 0;
          continue;
        }
        for (int lst = 0; lst < 3; lst++) {
          int p = pos[lst][cnt[lst]] - 1;
          if (p == -1) {
            d[k][v][x][lst] = 1e9;
            continue;
          }
          int useless = 0;
          for (int j = 0; j < 3; j++) {
            useless += max(0, pref[p][j] - cnt[j]);
          }
          if (lst == 0) {
            d[k][v][x][lst] = min(d[k - 1][v][x][0], d[k - 1][v][x][2]);
          } else if (lst == 1) {
            d[k][v][x][lst] = min(min(d[k][v - 1][x][0], d[k][v - 1][x][2]),
                                  d[k][v - 1][x][1]);
          } else {
            d[k][v][x][lst] = min(min(d[k][v][x - 1][0], d[k][v][x - 1][2]),
                                  d[k][v][x - 1][1]);
          }
          d[k][v][x][lst] += useless;
        }
      }
    }
  }
  int ans = 1e9;
  for (int j = 0; j < 3; j++) {
    ans = min(ans, d[pref[n - 1][0]][pref[n - 1][1]][pref[n - 1][2]][j]);
  }
  cout << ans << endl;
}
