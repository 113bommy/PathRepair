#include <bits/stdc++.h>
const int N = 100010;
const int inf = 0x3f3f3f3f;
using namespace std;
int n;
vector<int> vt[N];
void rotate(vector<int> &a) {
  int t = a[0];
  for (int i = 0; i < 3; i++) a[i] = a[i + 1];
  a[3] = t;
  return;
}
bool check(vector<int> a, vector<int> b) {
  for (int i = 0; i < 4; i++) {
    rotate(a);
    bool f = 1;
    for (int j = 0; j < 4; j++)
      if (a[j] != b[j]) f = 0;
    if (f) return 1;
  }
  return 0;
}
bool vis[1010];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    if (i) scanf("%*s");
    char s[3];
    scanf("%s", s);
    vt[i].push_back(s[0] - '0');
    vt[i].push_back(s[1] - '0');
    scanf("%s", s);
    vt[i].push_back(s[1] - '0');
    vt[i].push_back(s[0] - '0');
  }
  int ret = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    ret++;
    vis[i] = 1;
    for (int j = i + 1; j < n; j++)
      if (!vis[j] && check(vt[i], vt[j])) vis[j] = 1;
  }
  cout << ret << endl;
  return 0;
}
