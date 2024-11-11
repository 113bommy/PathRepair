#include <bits/stdc++.h>
using namespace std;
template <class T>
bool up_max(T& a, const T& b) {
  return b > a ? a = b, 1 : 0;
}
template <class T>
bool up_min(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
char str[100050];
long long cnt[26];
vector<int> vt[2][26];
void init(int cur) {
  for (int i = 0; i < 26; ++i) vt[cur][i].clear(), cnt[i] = 0;
}
int main() {
  int k, n;
  while (scanf("%s%d", str, &k) != EOF) {
    n = strlen(str);
    if ((long long)n * (n - 1) / 2 > (long long)k) {
      puts("No such line.");
      continue;
    }
    int cur = 0;
    init(cur);
    for (int i = 0; i < n; ++i) {
      cnt[str[i] - 'a'] += n - i;
      vt[cur][str[i] - 'a'].push_back(i);
    }
    string ret;
    while (k) {
      int i, sum = 0;
      for (i = 0; i < 26; ++i) {
        if (sum + cnt[i] >= k) {
          k -= sum;
          sum = 0;
          break;
        } else
          sum += cnt[i];
      }
      ret += 'a' + i;
      if (k <= vt[cur][i].size())
        break;
      else
        k -= vt[cur][i].size();
      init(cur ^ 1);
      for (int j = 0; j < vt[cur][i].size(); ++j) {
        int k = vt[cur][i][j] + 1;
        if (k >= n) continue;
        vt[cur ^ 1][str[k] - 'a'].push_back(k);
        cnt[str[k] - 'a'] += n - k;
      }
      cur ^= 1;
    }
    cout << ret << endl;
  }
}
