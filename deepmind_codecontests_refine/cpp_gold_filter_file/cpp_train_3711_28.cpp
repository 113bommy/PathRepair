#include <bits/stdc++.h>
using namespace std;
int read() {
  int xx = 0, ff = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    xx = xx * 10 + ch - '0';
    ch = getchar();
  }
  return xx * ff;
}
long long READ() {
  long long xx = 0, ff = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    xx = xx * 10 + ch - '0';
    ch = getchar();
  }
  return xx * ff;
}
const int maxn = 100010;
int N;
long long temp, ans[maxn], sta[65];
vector<long long> v[65];
int main() {
  sta[0] = 1;
  for (int i = 1; i <= 60; i++) sta[i] = sta[i - 1] * 2;
  N = read();
  for (int i = 1; i <= N; i++) {
    temp = READ();
    for (int j = 60; j >= 0; j--)
      if (temp & sta[j]) {
        v[j].push_back(temp);
        break;
      }
  }
  long long now = 0;
  for (int i = 1; i <= N; i++) {
    bool flag = 0;
    for (int j = 0; j <= 60; j++) {
      if ((sta[j] & now) == 0 && v[j].size()) {
        flag = 1;
        ans[i] = v[j][v[j].size() - 1];
        v[j].pop_back();
        now ^= ans[i];
        break;
      }
    }
    if (!flag) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  for (int i = 1; i <= N; i++) printf("%I64d ", ans[i]);
  puts("");
  return 0;
}
