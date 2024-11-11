#include <bits/stdc++.h>
using namespace std;
inline long long int StrToInt(string& s) {
  long long int ans = 0;
  for (int i = 0; i < s.size(); i++) ans = ans * 10 + s[i] - '0';
  return 0;
}
int arr[4];
bool was[4];
char mapp[40][40];
string in;
int ans = 0;
int x, y;
int tx[] = {0, 0, 1, -1};
int ty[] = {1, -1, 0, 0};
int n, m;
void rec(int cnt = 0) {
  if (cnt == 4) {
    int xx = x;
    int yy = y;
    for (int i = 0; i < in.size(); i++) {
      xx += tx[arr[in[i] - '0']];
      yy += ty[arr[in[i] - '0']];
      if (xx < 0 || yy < 0 || xx >= n || yy >= m || mapp[xx][yy] == '#') return;
      if (mapp[xx][yy] == 'E') {
        ans++;
        return;
      }
    }
  } else {
    for (int i = 0; i < 4; i++) {
      if (!was[i]) {
        was[i] = 1;
        arr[cnt] = i;
        rec(cnt + 1);
        was[i] = 0;
      }
    }
  }
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> mapp[i][j];
      if (mapp[i][j] == 'S') {
        x = i;
        y = j;
      }
    }
  cin >> in;
  rec();
  cout << ans;
  return 0;
}
