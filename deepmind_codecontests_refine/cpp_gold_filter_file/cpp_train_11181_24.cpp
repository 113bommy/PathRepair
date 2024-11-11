#include <bits/stdc++.h>
using namespace std;
int dis[30][30];
char c[100010];
int main() {
  for (int j = 0; j < 30; ++j) {
    for (int i = 0; i < 30; ++i) {
      dis[i][j] = dis[j][i] = 100000;
      if (i == j) dis[i][j] = 0;
    }
  }
  string a, b;
  getline(cin, a);
  getline(cin, b);
  int n;
  cin >> n;
  getchar();
  for (int i = 0; i < n; ++i) {
    string s;
    getline(cin, s);
    char ta = ' ', tc;
    int w = 0;
    for (int j = 0; j < s.size(); ++j) {
      if (islower(s[j])) {
        if (ta == ' ')
          ta = s[j];
        else
          tc = s[j];
      }
      while (isdigit(s[j])) {
        w = w * 10 + s[j] - '0';
        j++;
      }
    }
    dis[ta - 'a'][tc - 'a'] = min(w, dis[ta - 'a'][tc - 'a']);
  }
  if (a.size() != b.size()) {
    cout << "-1";
    return 0;
  } else {
    long long ans = 0;
    for (int j = 0; j < 30; ++j) {
      for (int i = 0; i < 30; ++i) {
        for (int k = 0; k < 30; ++k) {
          if (dis[i][k] > dis[i][j] + dis[j][k])
            dis[i][k] = dis[i][j] + dis[j][k];
        }
      }
    }
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] != b[i]) {
        char tmp = 'a';
        int mi = 100000, sa = a[i] - 'a', sb = b[i] - 'a';
        for (int j = 0; j < 26; ++j) {
          if (dis[sa][j] + dis[sb][j] < mi) {
            mi = dis[sa][j] + dis[sb][j];
            tmp = 'a' + j;
          }
        }
        if (mi == 100000) {
          cout << "-1";
          return 0;
        }
        c[i] = tmp;
        ans += mi;
      } else
        c[i] = a[i];
    }
    cout << ans << endl;
    cout << c;
  }
  return 0;
}
