#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
char s[N], ss[N];
int n0, nn, n;
int qs[10], qss[10];
char excl[N], perf[N], buf[N];
vector<string> cand;
void proc(int id) {
  string s(perf);
  s.insert(id, string(ss));
  cand.push_back(s);
}
int main() {
  scanf("%s", s);
  n0 = strlen(s);
  scanf("%s", ss);
  nn = strlen(ss);
  for (int i = 1; i <= 6; ++i) {
    n = n0 - i;
    assert(n >= 0);
    int q = 0, tmp = n;
    while (tmp) {
      q++;
      tmp /= 10;
    }
    if (q == i) break;
  }
  for (int i = 0; i < nn; ++i) qss[ss[i] - '0']++;
  for (int i = 0; i < n0; ++i) qs[s[i] - '0']++;
  int tmp = n;
  while (tmp) {
    int d = tmp % 10;
    qs[d]--;
    tmp /= 10;
  }
  for (int i = 0; i < 10; ++i) qs[i] -= qss[i];
  for (int i = 0; i < nn; ++i) {
    excl[i] = ss[i];
  }
  int sz = nn;
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < qs[i]; ++j) excl[sz++] = '0' + i;
  if (n == nn + qs[0]) {
    cout << excl << endl;
    return 0;
  }
  cand.push_back(string(excl));
  sz = 0;
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < qs[i]; ++j) perf[sz++] = '0' + i;
  swap(perf[0], perf[qs[0]]);
  vector<int> id;
  id.push_back(1);
  int sum[10];
  sum[0] = qs[0];
  for (int i = 1; i < 10; ++i) sum[i] = sum[i - 1] + qs[i];
  int d = ss[0] - '0';
  if (d > 0) {
    for (int i = -1; i <= 1; ++i) {
      if (sum[d - 1] + i >= 1 && sum[d - 1] + i <= sz - 1)
        id.push_back(sum[d - 1] + i);
    }
  }
  for (int i = -1; i <= 1; ++i) {
    if (sum[d] + i >= 1 && sum[d] + i <= sz - 1) id.push_back(sum[d] + i);
  }
  for (int idx : id) proc(idx);
  sort(cand.begin(), cand.end());
  for (int i = 0; i < cand.size(); ++i)
    if (cand[i][0] != '0') {
      printf("%s\n", cand[i].c_str());
      return 0;
    }
  assert(false);
  return 0;
}
