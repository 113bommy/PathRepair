#include <bits/stdc++.h>
using namespace std;
char ch[1000005];
int l[30], r[30];
int vis[1000005];
int main() {
  int n, k;
  cin >> n >> k;
  cin >> ch;
  memset(l, -1, sizeof(l));
  memset(r, -1, sizeof(r));
  for (int i = 0; ch[i]; i++) {
    int pow = ch[i] - 'A';
    if (l[pow] == -1) l[pow] = i;
    r[pow] = i;
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < 26; i++) {
    if (l[i] != -1) {
      for (int j = l[i]; j <= r[i]; j++) vis[j]++;
    }
  }
  int maxx = -1;
  for (int i = 0; ch[i]; i++) {
    maxx = max(vis[i], maxx);
  }
  if (k >= maxx)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
