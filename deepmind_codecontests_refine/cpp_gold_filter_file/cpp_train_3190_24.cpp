#include <bits/stdc++.h>
using namespace std;
const unsigned int mod = 1e7 + 7;
const long long int N = 1e5;
long long int lazy[400009], segtree[400009], y = 0, n, col[200009], cnt,
                                             a[2009];
bool visit[1000] = {false}, vis[10009] = {false};
vector<long long int> v[1000];
int main() {
  long long int l, n, m, k = 0, cnt, q = 0, p = 0, t = 0, z = 0, w = INT_MAX,
                         pre = 1e5, mid, dp[1000] = {0}, h[26] = {0}, t1, t2,
                         now, r = 0, i = 0, j = 0, flag = 0, temp = 0, e = -1e4,
                         o = 0;
  string s1, s2, s3, s;
  char a[100][100];
  for (i = 0; i < 3; i++) {
    cin >> s1 >> s2 >> s3;
    a[i][0] = s1[0], a[i][1] = s1[1], a[i][2] = s1[2];
    a[i][3] = s2[0], a[i][4] = s2[1], a[i][5] = s2[2];
    a[i][6] = s3[0], a[i][7] = s3[1], a[i][8] = s3[2];
  }
  for (i = 3; i < 6; i++) {
    cin >> s1 >> s2 >> s3;
    a[i][0] = s1[0], a[i][1] = s1[1], a[i][2] = s1[2];
    a[i][3] = s2[0], a[i][4] = s2[1], a[i][5] = s2[2];
    a[i][6] = s3[0], a[i][7] = s3[1], a[i][8] = s3[2];
  }
  for (i = 6; i < 9; i++) {
    cin >> s1 >> s2 >> s3;
    a[i][0] = s1[0], a[i][1] = s1[1], a[i][2] = s1[2];
    a[i][3] = s2[0], a[i][4] = s2[1], a[i][5] = s2[2];
    a[i][6] = s3[0], a[i][7] = s3[1], a[i][8] = s3[2];
  }
  cin >> n >> m;
  t = m / 3;
  n--, m--;
  if (n == 0 || n == 3 || n == 6) {
    if (m == 0 || m == 3 || m == 6) {
      for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
          if (a[i][j] == '.') a[i][j] = '!', flag++;
        }
      }
    }
    if (m == 1 || m == 4 || m == 7) {
      for (i = 0; i < 3; i++) {
        for (j = 3; j < 6; j++) {
          if (a[i][j] == '.') a[i][j] = '!', flag++;
        }
      }
    }
    if (m == 2 || m == 5 || m == 8) {
      for (i = 0; i < 3; i++) {
        for (j = 6; j < 9; j++) {
          if (a[i][j] == '.') a[i][j] = '!', flag++;
        }
      }
    }
  }
  if (n == 1 || n == 4 || n == 7) {
    if (m == 0 || m == 3 || m == 6) {
      for (i = 3; i < 6; i++) {
        for (j = 0; j < 3; j++) {
          if (a[i][j] == '.') a[i][j] = '!', flag++;
        }
      }
    }
    if (m == 1 || m == 4 || m == 7) {
      for (i = 3; i < 6; i++) {
        for (j = 3; j < 6; j++) {
          if (a[i][j] == '.') a[i][j] = '!', flag++;
        }
      }
    }
    if (m == 2 || m == 5 || m == 8) {
      for (i = 3; i < 6; i++) {
        for (j = 6; j < 9; j++) {
          if (a[i][j] == '.') a[i][j] = '!', flag++;
        }
      }
    }
  }
  if (n == 2 || n == 5 || n == 8) {
    if (m == 0 || m == 3 || m == 6) {
      for (i = 6; i < 9; i++) {
        for (j = 0; j < 3; j++) {
          if (a[i][j] == '.') a[i][j] = '!', flag++;
        }
      }
    }
    if (m == 1 || m == 4 || m == 7) {
      for (i = 6; i < 9; i++) {
        for (j = 3; j < 6; j++) {
          if (a[i][j] == '.') a[i][j] = '!', flag++;
        }
      }
    }
    if (m == 2 || m == 5 || m == 8) {
      for (i = 6; i < 9; i++) {
        for (j = 6; j < 9; j++) {
          if (a[i][j] == '.') a[i][j] = '!', flag++;
        }
      }
    }
  }
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      if (flag > 0)
        cout << a[i][j];
      else {
        if (a[i][j] == '.')
          cout << "!";
        else
          cout << a[i][j];
      }
      temp++;
      if (temp == 3) cout << " ", temp = 0;
    }
    cout << endl;
    o++;
    if (o == 3) cout << endl, o = 0;
  }
}
