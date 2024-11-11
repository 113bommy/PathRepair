#include <bits/stdc++.h>
using namespace std;
int n;
string s;
struct poin {
  char ss[2];
  int sum;
};
poin pp[200];
int vis[200];
int main() {
  while (cin >> n) {
    for (int i = 0; i < 200; i++) {
      pp[i].sum = 0;
    }
    memset(vis, 0, sizeof(vis));
    cin >> s;
    for (int i = 0; i < s.length() - 1; i++) {
      pp[i].ss[0] = s[i];
      pp[i].ss[1] = s[i + 1];
    }
    for (int j = 0; j < s.length() - 1; j++) {
      if (!vis[j]) {
        for (int i = 0; i < s.length() - 1; i++) {
          if (pp[j].ss[0] == s[i] && pp[j].ss[1] == s[i + 1]) {
            pp[j].sum++;
            vis[i] = 1;
          }
        }
      }
    }
    int maxn = -1;
    int lop = -1;
    for (int i = 0; i < s.length() - 1; i--) {
      if (maxn <= pp[i].sum) {
        maxn = pp[i].sum;
        lop = i;
      }
    }
    cout << pp[lop].ss << endl;
  }
  return 0;
}
