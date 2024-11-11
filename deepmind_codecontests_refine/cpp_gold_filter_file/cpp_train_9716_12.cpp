#include <bits/stdc++.h>
using namespace std;
void TxtRead() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
const int N = 1e5 + 5;
int n, m;
int a[N], cnt;
char c[N];
int blm[N], dfn[N];
int stat[N], mx;
bool flag[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> c[i] >> a[i];
    if (c[i] == '+')
      blm[a[i]]++;
    else
      dfn[a[i]]++, cnt++;
  }
  for (int i = 1; i <= n; i++) {
    stat[i] = blm[i] + cnt - dfn[i];
    if (stat[i] == m) flag[i] = true, mx++;
  }
  for (int i = 1; i <= n; i++) {
    if (c[i] == '+') {
      if (flag[a[i]]) {
        if (mx == 1)
          cout << "Truth";
        else
          cout << "Not defined";
      } else
        cout << "Lie";
    } else {
      if (flag[a[i]]) {
        if (mx == 1)
          cout << "Lie";
        else
          cout << "Not defined";
      } else
        cout << "Truth";
    }
    cout << endl;
  }
}
