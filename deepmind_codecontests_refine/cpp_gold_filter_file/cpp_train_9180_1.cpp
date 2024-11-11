#include <bits/stdc++.h>
using namespace std;
vector<int> tmp;
int sum[611111];
char s[611111];
int main() {
  int n;
  scanf("%d%s", &n, s + 1);
  int minnum = 1e9 + 7;
  for (int i = 1; i < n + 1; i++) {
    sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);
    if (sum[i] < minnum)
      tmp.clear(), minnum = sum[i], tmp.push_back(i);
    else if (sum[i] == minnum)
      tmp.push_back(i);
    sum[i + n] = sum[i], s[i + n] = s[i];
  }
  tmp.push_back(tmp[0] + n);
  if (sum[n] != 0) {
    printf("0\n1 1\n");
    return 0;
  }
  pair<int, int> res = {tmp.size() - 1, -1};
  for (int i = 1; i < tmp.size(); i++) {
    int k1 = tmp[i - 1], k2 = tmp[i], co1 = 0, co2 = 0;
    for (int i = k1 + 1; i < k2; i++)
      if (sum[i] == minnum + 1) co1++;
    if (co1) res = max(res, {co1, i});
  }
  int st = 0, ed = 0, nowst = 0, nowco = 0;
  for (int i = tmp[0]; i < tmp[0] + n; i++) {
    if (sum[i] < minnum + 2)
      nowco = 0, nowst = i + 1;
    else if (sum[i] == minnum + 2) {
      nowco++;
      if (nowco + tmp.size() - 1 > res.first)
        res.first = nowco + tmp.size() - 1, st = nowst, ed = i + 1;
    }
  }
  if (!st && res.second == -1)
    printf("%d\n%d %d\n", res.first, 1, 1);
  else if (!st)
    printf("%d\n%d %d\n", res.first, (tmp[res.second] - 1) % n + 1,
           tmp[res.second - 1] + 1);
  else {
    while (s[ed] != ')') ed++;
    while (s[st] != '(') st++;
    printf("%d\n%d %d\n", res.first, (st - 1) % n + 1, (ed - 1) % n + 1);
  }
}
