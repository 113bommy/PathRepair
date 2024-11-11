#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e2 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
int n;
char ss[MAX], tt[MAX];
int num[MAX];
vector<pair<int, int> > V;
void solve() {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (ss[i] == tt[i]) continue;
    for (int j = i + 1; j <= n; j++) {
      if (ss[j] != tt[j] && ss[j] == ss[i]) {
        V.push_back(make_pair(j, i));
        ss[j] = tt[i];
        cnt++;
        break;
      } else if (ss[j] != tt[j] && tt[j] == ss[i]) {
        V.push_back(make_pair(j, j));
        ss[j] = tt[j];
        V.push_back(make_pair(j, i));
        ss[i] = tt[i];
        cnt += 2;
        break;
      }
    }
  }
  printf("Yes\n%d\n", cnt);
  for (auto x : V) {
    printf("%d %d\n", x.first, x.second);
  }
}
int main() {
  int ks;
  scanf("%d", &ks);
  while (ks--) {
    for (int i = 0; i < 30; i++) num[i] = 0;
    V.clear();
    scanf("%d", &n);
    scanf("%s", ss + 1);
    scanf("%s", tt + 1);
    for (int i = 1; i <= n; i++) {
      num[ss[i] - 'a']++;
      num[tt[i] - 'a']++;
    }
    bool flg = true;
    for (int i = 0; i < 26; i++) {
      if (num[i] % 2 == 1) {
        flg = false;
        break;
      }
    }
    if (!flg) {
      puts("No");
    } else {
      solve();
    }
  }
  return 0;
}
