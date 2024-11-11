#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fast();
  string str;
  cin >> str;
  long long len = str.length();
  vector<long long> pos[26];
  for (long long i = 0; i < len; i++) pos[str[i] - 'a'].push_back(i);
  long long ans = len;
  for (long long i = 0; i < 26; i++) {
    if (pos[i].size() == 0) continue;
    long long val = pos[i][0] + 1;
    for (long long j = 1; j < pos[i].size(); j++)
      val = max(val, pos[i][j] - pos[i][j - 1]);
    val = max(val, len - pos[i][pos[i].size() - 1]);
    ans = min(ans, val);
  }
  cout << ans;
}
