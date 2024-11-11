#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long mod = 1e9 + 7;
const int N = 1e5 + 10;
int fdepth = 0;
string s;
int depth = -1;
long long pows[60];
map<long long, int> dir;
void calc(long long cur, long long val) {
  depth++;
  if (val == cur) return;
  if (val < cur) {
    long long low = cur - pows[fdepth - depth] + 1;
    long long high = cur - 1;
    dir[(low + high) / 2] = 1;
    calc((low + high) / 2, val);
  } else {
    long long low = cur + 1;
    long long high = cur + pows[fdepth - depth] - 1;
    dir[(low + high) / 2] = 2;
    calc((low + high) / 2, val);
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n;
  int q;
  cin >> n >> q;
  pows[0] = 1;
  for (int i = 1; i <= 59; ++i) pows[i] = 2 * pows[i - 1];
  long long total = n + 1;
  while (total > 1) {
    total /= 2;
    fdepth++;
  }
  fdepth--;
  for (int j = 1; j <= q; ++j) {
    long long start;
    cin >> start;
    cin >> s;
    depth = -1;
    calc((n + 1) / 2, start);
    for (int i = 0; i <= (int)s.size() - 1; ++i) {
      if (s[i] == 'U') {
        if (start == (n + 1) / 2) continue;
        if (dir[start] == 1) {
          start = (start + pows[fdepth - depth]);
          depth--;
        } else if (dir[start] == 2) {
          start = (start - pows[fdepth - depth]);
          depth--;
        }
      }
      if (s[i] == 'L') {
        if (depth == fdepth) continue;
        long long low = start - pows[fdepth - depth] + 1;
        long long high = start - 1;
        dir[(low + high) / 2] = 1;
        start = (low + high) / 2;
        depth++;
      }
      if (s[i] == 'R') {
        if (depth == fdepth) continue;
        long long low = start + 1;
        long long high = start + pows[fdepth - depth] - 1;
        dir[(low + high) / 2] = 2;
        start = (low + high) / 2;
        depth++;
      }
    }
    cout << start << endl;
  }
  return 0;
}
