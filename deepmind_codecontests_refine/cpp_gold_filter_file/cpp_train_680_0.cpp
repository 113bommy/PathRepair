#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int a[N], b[N];
vector<int> ed[N];
vector<pair<int, char> > ans[N];
int n, k, cnt;
int a1, a2;
void fun() {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    ed[cnt].push_back(a[i]);
    if (sum == b[cnt]) {
      cnt++;
      sum = 0;
    }
    if (sum > b[cnt]) return;
  }
}
bool cll(int cnt) {
  int mx = 0, id = 0;
  bool cp = 0;
  for (int i = 1; i < ed[cnt].size(); i++) {
    if (ed[cnt][i] != ed[cnt][i - 1]) {
      cp = 1;
      break;
    }
  }
  if (cp == 0 && ed[cnt].size() > 1)
    return 1;
  else
    return 0;
}
void ff(int cnt) {
  int mx = 0, id = 0, id1 = 0;
  for (int i = 1; i < ed[cnt].size(); i++) {
    if (ed[cnt][i - 1] < ed[cnt][i] && mx < ed[cnt][i]) {
      mx = ed[cnt][i];
      id = i;
      id1 = i - 1;
    }
  }
  for (int i = 0; i < ed[cnt].size() - 1; i++) {
    if (ed[cnt][i + 1] < ed[cnt][i] && mx < ed[cnt][i]) {
      mx = ed[cnt][i];
      id = i;
      id1 = i + 1;
    }
  }
  if (id < id1) {
    while (id1 < ed[cnt].size()) {
      ans[cnt].push_back(make_pair(id, 'R'));
      id1++;
    }
    while (id > 0) {
      ans[cnt].push_back(make_pair(id, 'L'));
      id--;
    }
  } else {
    id1 = id + 1;
    while (id > 0) {
      ans[cnt].push_back(make_pair(id, 'L'));
      id--;
    }
    while (id1 < ed[cnt].size()) {
      ans[cnt].push_back(make_pair(id, 'R'));
      id1++;
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a1 += a[i];
  }
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &b[i]);
    a2 += b[i];
  }
  cnt = 1;
  fun();
  if (cnt <= k || a1 != a2)
    cout << "NO" << endl;
  else {
    cnt = 1;
    while (cnt <= k) {
      if (cll(cnt)) {
        puts("NO");
        return 0;
      }
      cnt++;
    }
    for (int i = 1; i <= k; i++) ff(i);
    puts("YES");
    for (int i = 1; i <= k; i++) {
      for (int j = 0; j < ans[i].size(); j++) {
        cout << i + ans[i][j].first << ' ' << ans[i][j].second << endl;
      }
    }
  }
}
