#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> r(n), c(n), posr(n), posc(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &r[i]);
    r[i]--;
    posr[r[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
    c[i]--;
    posc[c[i]] = i;
  }
  vector<pair<int, int> > ans1, ans2;
  for (int i = 0; i < n; i++) {
    if (posr[i] == i && posc[i] == i) continue;
    int nowr = posr[i];
    int nowc = posc[i];
    r[nowr] = r[i];
    c[nowc] = c[i];
    posr[r[i]] = nowr;
    posc[c[i]] = nowc;
    ans1.push_back(make_pair(nowr + 1, i + 1));
    ans2.push_back(make_pair(i + 1, nowc + 1));
  }
  cout << ans1.size() << endl;
  for (int i = 0; i < (int)ans1.size(); i++) {
    cout << ans1[i].first << " " << ans1[i].second << " ";
    cout << ans2[i].first << " " << ans2[i].second << endl;
  }
  return 0;
}
