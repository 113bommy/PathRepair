#include <bits/stdc++.h>
using namespace std;
const long long nInf = -1000000000;
const long long pInf = 1000000000;
const long long mod = 1000000007;
const int MAXN = 150;
void getdata();
void preproc();
void solve();
string s[3];
int n, k;
int ph;
bool used[3][MAXN];
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    getdata();
    preproc();
    solve();
  }
  return 0;
}
void getdata() {
  scanf("%d %d", &n, &k);
  scanf("\n");
  ph = -1;
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
    s[i] = s[i] + "&&&&";
    if (s[i][0] == 's') ph = i;
  }
}
void preproc() {}
void solve() {
  for (int i = 0; i < MAXN; i++) {
    for (int j = 0; j < 3; j++) {
      used[j][i] = false;
    }
  }
  queue<pair<int, int> > q;
  q.push(make_pair(ph, 0));
  while (!q.empty()) {
    auto pos = q.front();
    int x = pos.first;
    int y = pos.second;
    q.pop();
    if (y >= n - 1) {
      printf("YES\n");
      return;
    }
    if (x > 0 && (s[x][y + 1] == '.' && s[x - 1][y + 1] == '.' &&
                  s[x - 1][y + 2] == '.' && s[x - 1][y + 3] == '.')) {
      if (!used[x - 1][y + 3]) {
        q.push(make_pair(x - 1, y + 3));
        used[x - 1][y + 3] = true;
      }
    }
    if (x < 2 && (s[x][y + 1] == '.' && s[x + 1][y + 1] == '.' &&
                  s[x + 1][y + 2] == '.' && s[x + 1][y + 3] == '.')) {
      if (!used[x + 1][y + 3]) {
        q.push(make_pair(x + 1, y + 3));
        used[x + 1][y + 3] = true;
      }
    }
    if ((s[x][y + 1] == '.' && s[x][y + 2] == '.' && s[x][y + 3] == '.')) {
      if (!used[x][y + 3]) {
        used[x][y + 3] = true;
        q.push(make_pair(x, y + 3));
      }
    }
  }
  printf("NO\n");
}
