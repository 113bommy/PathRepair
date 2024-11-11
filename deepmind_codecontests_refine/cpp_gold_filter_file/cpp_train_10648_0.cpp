#include <bits/stdc++.h>
template <typename T>
void read(T& re) {
  re = 0;
  int re2 = 1;
  char ch = '!';
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') re2 = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') {
    re = re * 10 + ch - '0';
    ch = getchar();
  }
  re *= re2;
}
template <typename T, typename... Args>
void read(T& re, Args&... args) {
  read(re);
  read(args...);
}
template <typename T>
void write(T A) {
  if (A < 0) {
    A = -A;
    putchar('-');
  }
  if (A / 10) write(A / 10);
  putchar(A % 10 + '0');
}
int T;
const int MAXN = 2e5 + 7;
int n, n2;
int a[MAXN];
int app[MAXN], maxx1, maxx2;
std::vector<std::pair<int, int> > pos[MAXN];
int ans;
int mp[MAXN << 1];
void getans1(int col) {
  memset(mp, 0x3f, sizeof(mp));
  mp[n] = 0;
  for (int i = 1, cnt = 0; i <= n; i++) {
    if (a[i] == maxx2) cnt++;
    if (a[i] == col) cnt--;
    ans = (ans > i - mp[cnt + n] ? ans : i - mp[cnt + n]);
    mp[cnt + n] = (mp[cnt + n] > i ? i : mp[cnt + n]);
  }
}
std::vector<std::pair<int, int> > pos2;
void getans2(int col) {
  pos2.clear();
  int now1, cnt = 1;
  std::vector<std::pair<int, int> >::iterator I =
      lower_bound(pos[maxx2].begin(), pos[maxx2].end(), pos[col][0]);
  if (I == pos[maxx2].end())
    now1 = maxx1 - 1;
  else
    now1 = I->second;
  now1 = (now1 - app[col] - 1 > 0 ? now1 - app[col] - 1 : 0);
  int now2 = 0;
  while (now1 < (int)pos[maxx2].size() && now2 < (int)pos[col].size() &&
         cnt <= (int)pos[col].size() * 2 + 1) {
    if (pos[maxx2][now1].first < pos[col][now2].first) {
      pos2.push_back(std::make_pair(pos[maxx2][now1].first, -1));
      now1++;
      cnt++;
    } else {
      pos2.push_back(std::make_pair(pos[col][now2].first, 1));
      now2++;
    }
  }
  while (now1 < (int)pos[maxx2].size() && cnt <= (int)pos[col].size() * 2 + 1) {
    pos2.push_back(std::make_pair(pos[maxx2][now1].first, -1));
    now1++;
    cnt++;
  }
  while (now2 < (int)pos[col].size()) {
    pos2.push_back(std::make_pair(pos[col][now2].first, 1));
    now2++;
  }
  memset(mp, 0x3f, sizeof(mp));
  mp[n] = pos2[0].first - 1;
  for (int i = 0, cnt2 = 0; i < pos2.size(); i++) {
    cnt2 += pos2[i].second;
    if (i != pos2.size() - 1)
      ans = (ans > pos2[i + 1].first - 1 - mp[cnt2 + n]
                 ? ans
                 : pos2[i + 1].first - 1 - mp[cnt2 + n]);
    else {
      if (now1 < pos[maxx2].size())
        ans = (ans > pos[maxx2][now1].first - 1 - mp[cnt2 + n]
                   ? ans
                   : pos[maxx2][now1].first - 1 - mp[cnt2 + n]);
      else
        ans = (ans > n - mp[cnt2 + n] ? ans : n - mp[cnt2 + n]);
    }
    mp[cnt2 + n] =
        (mp[cnt2 + n] > pos2[i].first ? pos2[i].first : mp[cnt2 + n]);
  }
}
int main() {
  T = 1;
  while (T--) {
    maxx1 = 0;
    read(n);
    n2 = sqrt(n);
    for (int i = 1, i2; i <= n; i++) {
      read(a[i]);
      i2 = pos[a[i]].size();
      pos[a[i]].push_back(std::make_pair(i, i2));
      app[a[i]]++;
      if (app[a[i]] > maxx1) {
        maxx1 = app[a[i]];
        maxx2 = a[i];
      }
    }
    for (int i = 1; i <= n; i++) {
      if (!app[i]) continue;
      if (i == maxx2) continue;
      if (app[i] >= n2)
        getans1(i);
      else
        getans1(i);
    }
    std::cout << ans << std::endl;
  }
  return 0;
}
