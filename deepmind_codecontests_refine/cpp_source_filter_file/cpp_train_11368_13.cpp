#include <bits/stdc++.h>
using namespace std;
int primes[1123];
void genprime() {
  memset(primes, 0, sizeof(primes));
  int i, j;
  primes[0] = primes[1] = 1;
  for (i = 2; i < 1123; i++) {
    if (primes[i] == 0) {
      for (j = i + i; j < 1123; j += i) primes[j] = 1;
    }
  }
}
vector<int> a[1123];
vector<pair<int, int> > cnts;
bool visited[1123];
int dfs(int at) {
  int ret = 1;
  visited[at] = true;
  int i;
  for (i = 0; i < a[at].size(); i++)
    if (!visited[a[at][i]]) ret += dfs(a[at][i]);
  return ret;
}
int main() {
  genprime();
  char inp[1123];
  int cnt[26];
  memset(cnt, 0, sizeof(cnt));
  int i, j;
  scanf("%s", inp);
  int n = strlen(inp);
  for (i = 0; i < n; i++) cnt[inp[i] - 'a']++;
  int ids[1123];
  memset(ids, -1, sizeof(ids));
  int cid = 0;
  for (i = 1; i <= n; i++)
    if (primes[i] == 0)
      for (j = i + i; j <= n; j += i) {
        a[i].push_back(i * j);
        a[i * j].push_back(i);
      }
  for (i = 1; i <= n; i++) {
    if (!visited[i]) {
      int cnt = dfs(i);
      cnts.push_back(make_pair(cnt, i));
    }
  }
  sort(cnts.begin(), cnts.end());
  reverse(cnts.begin(), cnts.end());
  vector<pair<int, int> > sizes;
  for (i = 0; i < 26; i++)
    if (cnt[i]) sizes.push_back(make_pair(cnt[i], i));
  sort(sizes.begin(), sizes.end());
  reverse(sizes.begin(), sizes.end());
  int bigset = cnts[0].first;
  char ans[1123];
  memset(ans, 0, sizeof(ans));
  if (sizes[0].first >= bigset) {
    printf("YES\n");
    for (i = 1; i <= n; i++) {
      if ((!primes[i] && i > n / 2))
        continue;
      else {
        ans[i] = sizes[0].second + 'a';
        sizes[0].first--;
      }
    }
    int pt = 0;
    for (i = 1; i <= n; i++) {
      while (sizes[pt].first <= 0) pt++;
      if (ans[i] == 0) {
        ans[i] = sizes[pt].second + 'a';
        sizes[pt].first--;
      }
    }
    printf("%s\n", ans + 1);
  } else {
    printf("NO\n");
  }
}
