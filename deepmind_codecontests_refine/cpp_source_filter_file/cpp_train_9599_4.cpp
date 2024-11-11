#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > E[2005];
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      scanf(" %c", &c);
      if (c == '1') {
        v.push_back(make_pair(i, j));
        E[i].push_back(make_pair(i, j));
        E[j].push_back(make_pair(i, j));
      }
    }
  }
  if (n > 10) {
    int cnt[2005];
    int tmp[2005];
    memset(cnt, 0, sizeof(cnt));
    memset(tmp, 0, sizeof(tmp));
    for (auto it : v) cnt[it.first]++, tmp[it.first]++;
    sort(cnt, cnt + n);
    int ok = 1;
    int tot = 0;
    for (int i = 0; i < n - 1; i++) {
      tot += cnt[i];
      if (tot == (i) * (i + 1) / 2) {
        ok = 0;
      }
    }
    if (ok) {
      printf("0 1\n");
    } else {
      long long ans = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cnt[j] = tmp[j];
        }
        for (auto it : E[i]) {
          if (it.first == i)
            cnt[i]--, cnt[it.second]++;
          else
            cnt[i]++, cnt[it.first]--;
        }
        sort(cnt, cnt + n);
        int tot = 0, ok = 1;
        for (int i = 0; i < n - 1; i++) {
          tot += cnt[i];
          if (tot == i * (i + 1) / 2) ok = 0;
        }
        ans += ok;
      }
      printf("1 %lld\n", ans);
    }
  } else {
    int Min = 1e9, ans = 0;
    for (int i = 0; i < (1 << n); i++) {
      int cnt[20];
      memset(cnt, 0, sizeof(cnt));
      for (auto it : v) {
        int a = i & (1 << it.first), b = i & (1 << it.second);
        if ((a && b) || (!a && !b))
          cnt[it.first]++;
        else
          cnt[it.second]++;
      }
      sort(cnt, cnt + n);
      int tot = 0;
      int ok = 1;
      for (int j = 0; j < n - 1; j++) {
        tot += cnt[j];
        if (tot == j * (j + 1) / 2) ok = 0;
      }
      if (ok) {
        int num = __builtin_popcount(i);
        if (Min > num) Min = num;
        if (Min == num) ans++;
      }
    }
    if (ans == 0)
      printf("-1\n");
    else {
      for (int i = 1; i <= Min; i++) ans *= i;
      printf("%d %d\n", Min, ans);
    }
  }
}
