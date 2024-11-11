#include <bits/stdc++.h>
using namespace std;
map<string, int> my;
int n, m;
string var[5006];
string bit[5006];
int op[5006][2];
int opera[5006];
int ans[5005][1003];
int print1[1005], print2[1005];
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 1; i <= n; i++) {
    string z;
    cin >> z;
    my[z] = i;
    var[i] = z;
    cin >> z;
    cin >> z;
    if (z[0] == '?') {
      op[i][0] = 0;
      cin >> z;
      if (z[0] == 'A')
        opera[i] == 1;
      else if (z[0] == 'O')
        opera[i] = 2;
      else
        opera[i] = 3;
      cin >> z;
      if (z[0] == '?')
        op[i][1] = 0;
      else
        op[i][1] = my[z];
    } else if (z[0] == '0' || z[0] == '1')
      bit[i] = z;
    else {
      op[i][0] = my[z];
      cin >> z;
      if (z[0] == 'A')
        opera[i] == 1;
      else if (z[0] == 'O')
        opera[i] = 2;
      else
        opera[i] = 3;
      cin >> z;
      if (z[0] == '?')
        op[i][1] = 0;
      else
        op[i][1] = my[z];
    }
  }
  for (int i = 0; i < m; i++) {
    int cnt[2];
    cnt[0] = cnt[1] = 0;
    for (int j = 0; j <= 1; j++) {
      for (int k = 1; k <= n; k++) {
        if (opera[k] == 0) {
          ans[k][i] = bit[k][i] - '0';
          cnt[j] += ans[k][i];
        } else {
          int v1 = op[k][0], v2 = op[k][1];
          if (v1 == 0) ans[v1][i] = j;
          if (v2 == 0) ans[v2][i] = j;
          if (opera[k] == 1)
            ans[k][i] = ans[v1][i] & ans[v2][i];
          else if (opera[k] == 2)
            ans[k][i] = ans[v1][i] | ans[v2][i];
          else
            ans[k][i] = ans[v1][i] ^ ans[v2][i];
          cnt[j] += ans[k][i];
        }
      }
    }
    if (cnt[0] > cnt[1]) {
      print1[i] = 0;
      print2[i] = 1;
    } else if (cnt[0] < cnt[1]) {
      print1[i] = 1;
      print2[i] = 0;
    } else {
      print1[i] = 0;
      print2[i] = 0;
    }
  }
  for (int i = 0; i < m; i++) cout << print2[i];
  cout << endl;
  for (int i = 0; i < m; i++) cout << print1[i];
}
