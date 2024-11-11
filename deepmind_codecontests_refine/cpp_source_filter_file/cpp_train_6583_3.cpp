#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  char c;
  int f = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') f = -1;
  x = (c & 15);
  while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + (c & 15);
  x *= f;
}
int n, m, i, j, g[8005][8005], deg[8005];
long long ans;
queue<int> qx;
bool cmp(int x, int y) { return g[x][y]; }
int main() {
  scanf("%d", &n);
  for ((i) = 1; (i) <= (n); (i)++) {
    getchar();
    for ((j) = 1; (j) <= (n / 4); (j)++) {
      char c = getchar();
      int t = (c <= '9' ? (c & 15) : (c - 'A' + 10));
      g[i][j * 4 - 3] = !!(t & 8);
      g[i][j * 4 - 2] = !!(t & 4);
      g[i][j * 4 - 1] = !!(t & 2);
      g[i][j * 4] = !!(t & 1);
    }
  }
  for ((i) = 1; (i) <= (n); (i)++) {
    for ((j) = 1; (j) <= (n); (j)++)
      if (i != j && g[i][j]) {
        deg[j]++;
      }
  }
  for ((i) = 1; (i) <= (n); (i)++) {
    if (!deg[i]) {
      qx.push(i);
      deg[i] = -1;
    }
  }
  int cnt = n;
  while (!qx.empty()) {
    int x = qx.front();
    qx.pop();
    cnt--;
    ans += 1ll * cnt * (614ll * n + 1);
    for ((i) = 1; (i) <= (n); (i)++)
      if (g[x][i] && --deg[i] == 0) {
        deg[i] = -1;
        qx.push(i);
      }
  }
  if (cnt == 0) {
    cout << ans << endl;
    return 0;
  }
  int x = 0;
  for ((i) = 1; (i) <= (n); (i)++)
    if (deg[i] != -1) x = i;
  vector<int> s1, s2;
  for ((i) = 1; (i) <= (n); (i)++)
    if (deg[i] != -1) {
      if (i == x || g[i][x]) {
        s1.push_back(i);
      } else {
        s2.push_back(i);
      }
    }
  sort(s1.begin(), s1.end(), cmp);
  sort(s2.begin(), s2.end(), cmp);
  ans += 3ll * s1.size() * s2.size();
  for ((i) = 0; (i) < (s1.size()); (i)++) deg[s1[i]] -= i;
  for ((i) = 0; (i) < (s2.size()); (i)++) deg[s2[i]] -= i;
  for ((i) = 0; (i) < (s1.size()); (i)++)
    for ((j) = 0; (j) < (i); (j)++) {
      ans += (deg[s1[i]] == deg[s1[j]]) ? 4 : 3;
    }
  for ((i) = 0; (i) < (s2.size()); (i)++)
    for ((j) = 0; (j) < (i); (j)++) {
      ans += (deg[s2[i]] == deg[s2[j]]) ? 4 : 3;
    }
  cout << ans << endl;
  return 0;
}
