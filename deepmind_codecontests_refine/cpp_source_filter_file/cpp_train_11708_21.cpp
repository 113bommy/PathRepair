#include <bits/stdc++.h>
using namespace std;
int n, m;
int value[50][50];
int mas[50];
int error[50];
int cnt[3];
int a[2][1 << 20][12];
int kolvo[1 << 20];
long long answer;
void solution(int flag, int L, int R) {
  int Length = R - L + 1;
  for (int mask = 0; mask <= ((1 << Length) - 1); mask++) {
    cnt[flag]++;
    for (int i = 1; i <= m; i++) {
      a[flag][cnt[flag]][i] = 0;
      for (int j = L; j <= R; j++) {
        int cnt1 = value[i][j];
        int cnt2 = 1 << (j - L);
        cnt2 &= mask;
        if (cnt2 > 0) cnt2 = 1;
        if (cnt1 == cnt2) a[flag][cnt[flag]][i]++;
      }
    }
  }
}
bool good(int flag, int x, int y) {
  for (int i = 1; i <= m; i++) {
    if (a[flag][x][i] == a[flag][y][i]) continue;
    if (a[flag][x][i] < a[flag][y][i])
      return true;
    else if (a[flag][x][i] > a[flag][y][i])
      return false;
  };
  return false;
}
void _sort(int flag, int L, int R) {
  int i = L;
  int j = R;
  while (1 == 1) {
    while (good(flag, i, (L + R) / 2)) i++;
    while (good(flag, (L + R) / 2, j)) j--;
    if (i <= j) {
      for (int k = 1; k <= m; k++) swap(a[flag][i][k], a[flag][j][k]);
      i++;
      j--;
    }
    if (i > j) break;
  }
  if (L <= j) _sort(flag, L, j);
  if (i <= R) _sort(flag, i, R);
}
bool two(int flag, int x, int y) {
  for (int i = 1; i <= m; i++)
    if (a[flag][x][i] != a[flag][y][i]) return false;
  return true;
}
bool sol(int MID) {
  for (int i = 1; i <= m; i++)
    if (mas[i] != a[1][MID][i]) {
      if (mas[i] < a[1][MID][i]) return true;
      return false;
    }
};
bool eq(int MID) {
  for (int i = 1; i <= m; i++)
    if (mas[i] != a[1][MID][i]) return false;
  return true;
};
void print(int ind) {
  for (int i = 1; i <= cnt[ind]; i++) {
    for (int j = 1; j <= m; j++) cout << a[ind][i][j] << " ";
    cout << endl;
  }
}
long long _find() {
  int L = 1;
  int R = cnt[1];
  int MID;
  while (R - L > 1) {
    MID = (R + L) / 2;
    if (eq(MID)) return kolvo[MID];
    if (sol(MID))
      R = MID;
    else
      L = MID;
  }
  if (eq(L)) return kolvo[L];
  if (eq(R)) return kolvo[R];
  return 0;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= n; j++)
      if (s[j - 1] == '0')
        value[i][j] = 0;
      else
        value[i][j] = 1;
    cin >> error[i];
  }
  cnt[0] = cnt[1] = 0;
  int middle = (n + 1) / 2;
  solution(0, 1, middle);
  solution(1, middle + 1, n);
  _sort(0, 1, cnt[0]);
  for (int iter = 1; iter <= 3; iter++) _sort(1, 1, cnt[1]);
  kolvo[1] = 1;
  int cur = 1;
  for (int i = 2; i <= cnt[1]; i++)
    if (two(1, cur, i))
      kolvo[cur]++;
    else {
      cur++;
      kolvo[cur] = 1;
      for (int j = 1; j <= m; j++) a[1][cur][j] = a[1][i][j];
    }
  cnt[1] = cur;
  answer = 0;
  for (int i = 1; i <= cnt[0]; i++) {
    for (int j = 1; j <= m; j++) mas[j] = error[j] - a[0][i][j];
    answer = answer + _find();
  }
  cout << answer << endl;
  return 0;
}
