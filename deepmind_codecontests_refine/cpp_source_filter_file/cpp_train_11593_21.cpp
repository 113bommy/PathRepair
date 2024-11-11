#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 28;
struct node {
  string name;
  int score;
  int total, mis;
  int tt;
} a[4];
map<string, int> mp;
int cmp(node x, node y) {
  if (x.score == y.score) {
    if (x.mis == y.mis) {
      if (x.total == y.total) return x.name < y.name;
      return x.total > y.total;
    }
    return x.mis > y.mis;
  }
  return x.score > y.score;
}
pair<int, int> ans;
int s, e;
int check(int k, int y) {
  a[e].mis -= k;
  a[s].mis += k;
  a[s].total += y + k;
  a[e].total += y;
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    if (i == s) continue;
    if (cmp(a[s], a[i])) cnt++;
  }
  if (cnt >= 2) {
    a[e].mis += k;
    a[s].mis -= k;
    a[s].total -= y + k;
    a[e].total -= y;
    ans.first = y + k;
    ans.second = y;
    return 1;
  }
  a[e].mis += k;
  a[s].mis -= k;
  a[s].total -= y + k;
  a[e].total -= y;
  return 0;
}
int solve(int k) {
  int flag = 0;
  int left = 0, right = inf, mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (check(k, mid)) {
      right = mid - 1;
      flag = 1;
    } else
      left = mid + 1;
  }
  return flag;
}
int main() {
  int x, y;
  string str1, str2;
  int cnt = 0;
  for (int i = 0; i < 5; i++) {
    cin >> str1 >> str2;
    scanf("%d:%d", &x, &y);
    if (mp.find(str1) == mp.end()) {
      mp[str1] = cnt++;
      a[mp[str1]].name = str1;
    }
    if (mp.find(str2) == mp.end()) {
      mp[str2] = cnt++;
      a[mp[str2]].name = str2;
    }
    if (x > y)
      a[mp[str1]].score += 3;
    else if (x == y) {
      a[mp[str1]].score++;
      a[mp[str2]].score++;
    } else
      a[mp[str2]].score += 3;
    a[mp[str1]].tt++;
    a[mp[str2]].tt++;
    a[mp[str1]].total += x;
    a[mp[str1]].mis += x - y;
    a[mp[str2]].total += x;
    a[mp[str2]].mis += y - x;
  }
  a[mp["BERLAND"]].score += 3;
  sort(a, a + 4, cmp);
  mp.clear();
  for (int i = 0; i < 4; i++) {
    mp[a[i].name] = i;
    if (a[i].tt < 3 && a[i].name != "BERLAND") e = i;
  }
  s = mp["BERLAND"];
  if (s <= 1) {
    printf("1:0\n");
  } else {
    int left = 0, right = 10000, mid;
    while (left <= right) {
      mid = (left + right) / 2;
      if (solve(mid))
        right = mid - 1;
      else
        left = mid + 1;
    }
    if (ans.first == 0 && 0 == ans.second)
      printf("IMPOSSIBLE\n");
    else
      printf("%d:%d\n", ans.first, ans.second);
  }
}
