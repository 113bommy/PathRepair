#include <bits/stdc++.h>
using namespace std;
const int SZ = 5010, INF = 0x7FFFFFFF;
bool vst[26];
set<int> st[26];
short cnt[SZ][26];
double work(int n, const string &str) {
  int res = 0;
  for (int i = 0; i < 26; ++i) {
    if (st[i].size() == 0) continue;
    memset(cnt, 0, sizeof(cnt));
    for (auto it = st[i].begin(); it != st[i].end(); ++it) {
      int pos = *it;
      for (int j = 1; j < n - 1; ++j) {
        ++cnt[j][str[(pos + j) % n] - 'a'];
      }
    }
    bool ok = 0;
    int maxv = 0;
    for (int j = 1; j < n - 1; ++j) {
      maxv = max(maxv, (int)count(cnt[j], cnt[j] + 26, 1));
    }
    res += maxv;
  }
  return (double)res / str.size();
}
int main() {
  std::ios::sync_with_stdio(0);
  {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
      st[str[i] - 'a'].insert(i);
    }
    cout << fixed << setprecision(7) << work(str.size(), str) << endl;
  }
  return 0;
}
