#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, char> > s, t, p;
vector<int> z;
int n, m;
long long ans = 0ll;
char myget() {
  char res = '!';
  while (!(res >= 'a' && res <= 'z')) res = getc(stdin);
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  scanf("%d%d", &m, &n);
  s.resize(n);
  t.resize(m);
  int last = -1;
  for (int i = 0; i < m; i++) {
    int cnt;
    scanf("%d", &cnt);
    char c = myget();
    if (last != -1 && t[last].second == c) {
      t[last].first += cnt;
    } else {
      last++;
      t[last] = make_pair(cnt, c);
    }
  }
  m = last + 1;
  last = -1;
  for (int i = 0; i < n; i++) {
    int cnt;
    scanf("%d", &cnt);
    char c = myget();
    if (last != -1 && s[last].second == c) {
      s[last].first += cnt;
    } else {
      last++;
      s[last] = make_pair(cnt, c);
    }
  }
  n = last + 1;
  if (n == 1) {
    for (int i = 0; i < m; i++) {
      if (s[0].second == t[i].second) {
        ans += max(0ll, t[i].first - s[0].first + 1ll);
      }
    }
    cout << ans << endl;
    return 0;
  }
  if (n == 2) {
    for (int i = 1; i < m; i++) {
      if (s[0].second == t[i - 1].second && s[1].second == t[i].second &&
          s[0].first <= t[i - 1].first && s[1].first <= t[i].first)
        ans++;
    }
    cout << ans << endl;
    return 0;
  }
  p.resize(n - 2 + 1 + m);
  z.resize(n - 2 + 1 + m);
  int cp = 0;
  for (int i = 1; i < n - 1; i++) {
    p[cp] = s[i];
    cp++;
  }
  pair<long long, char> dvr = make_pair(0, '#');
  p[cp] = dvr;
  cp++;
  for (int i = 0; i < m; i++) {
    p[cp] = t[i];
    cp++;
  }
  for (int i = 1, l = 0, r = 0; i < n - 2 + 1 + m; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n - 2 + 1 + m && p[z[i]] == p[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  for (int i = n - 2 + 1; i < n - 2 + 1 + m; i++) {
    if (z[i] < n - 2) continue;
    if (i == 0 || p[i - 1].second != s[0].second || p[i - 1].first < s[0].first)
      continue;
    if (i + n - 2 >= n - 2 + 1 + m || p[i + n - 2].second != s[n - 1].second ||
        p[i + n - 2].first < s[n - 1].first)
      continue;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
