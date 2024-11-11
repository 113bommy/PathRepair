#include <bits/stdc++.h>
inline int read() {
  int ret;
  scanf("%d", &ret);
  return ret;
}
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
using namespace std;
char s[1234567];
int n;
int p[1234567], p1[1234567];
void update(int k, int d) {
  int cnt = 0;
  for (int i = 0; i < int(d); i++) {
    for (int j = i; j < k; j += d) p1[cnt++] = j;
  }
  for (int i = k; i < n; i++) p1[i] = i;
  for (int i = 0; i < int(n - 1); i++) p[i] = p1[i + 1];
  p[n - 1] = p1[0];
  int many = n - k + 1;
  static bool visit[1234567];
  for (int i = 0; i < int(n); i++) visit[i] = false;
  static int last[1234567], all;
  static int rank[1234567];
  for (int i = 0; i < int(n); i++)
    if (visit[i] == false) {
      all = 0;
      last[all++] = i;
      visit[i] = true;
      int j = p[i];
      while (j != i) {
        last[all++] = j;
        visit[j] = true;
        j = p[j];
      }
      for (int x = 0; x < int(all); x++) {
        int y = (x + many) % all;
        rank[last[x]] = last[y];
      }
    }
  static char str[1234567];
  for (int i = 0; i < int(n); i++) {
    int j = (i - many + n) % n;
    str[i] = s[rank[j]];
  }
  for (int i = 0; i < int(n); i++) s[i] = str[i];
}
int Main() {
  ios_base::sync_with_stdio(0);
  cin >> s;
  n = strlen(s);
  int m;
  cin >> m;
  while (m--) {
    int k, d;
    cin >> k >> d;
    update(k, d);
    puts(s);
  }
  return 0;
}
int main() { return Main(); }
