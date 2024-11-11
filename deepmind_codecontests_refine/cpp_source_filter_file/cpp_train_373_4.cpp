#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, mod = 1000000007;
const double pi = 3.1415926535897932, eps = 1e-6;
void chmax(int &x, int y) {
  if (x < y) x = y;
}
void chmin(int &x, int y) {
  if (x > y) x = y;
}
int B = 333;
int n, top = 101000, cnt;
string s[100005];
int val[100005], ex[100005];
long long sum[444][5];
int num[444], rea[100005];
map<int, int> mp;
void calc(int x) {
  int lb = x * B, rb = (x + 1) * B;
  int now_cnt = 0;
  for (int(i) = (0); (i) <= (4); (i)++) sum[x][i] = 0;
  num[x] = 0;
  for (int(i) = (lb); (i) < (rb); (i)++) {
    if (ex[i]) {
      sum[x][now_cnt % 5] += rea[i];
      now_cnt++;
    }
  }
  num[x] = now_cnt;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int(i) = (1); (i) <= (n); (i)++) {
    cin >> s[i];
    if (s[i] != "sum") {
      cin >> val[i];
      mp[val[i]] = 0;
    }
  }
  for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
    rea[cnt] = it->first;
    it->second = cnt++;
  }
  for (int(i) = (1); (i) <= (n); (i)++) {
    if (s[i] == "sum") {
      int Top = top / B + 1;
      int now_cnt = 0;
      long long ans = 0;
      for (int(i) = (0); (i) <= (Top); (i)++) {
        ans += sum[i][(2 - now_cnt + 555555555) % 5];
        now_cnt += num[i];
      }
      cout << ans << '\n';
    } else {
      val[i] = mp[val[i]];
      if (s[i] == "add") {
        int v = val[i];
        ex[v] = 1;
        int at = v / B;
        calc(at);
      } else {
        int v = val[i];
        ex[v] = 0;
        int at = v / B;
        calc(at);
      }
    }
  }
}
