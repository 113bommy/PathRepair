#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int MAXN = 200100;
int n, m, p;
string a, b;
long long num[10];
long long pr = 1, nx = 9;
long long cnt = 0;
string res1 = "", res2 = "";
void solve() {
  cin >> a >> b;
  int n = a.size();
  for (int i = 0; i < n; ++i) {
    num[a[i] - '0']++;
  }
  for (int i = 1; i < 10; ++i) {
    if ((n - i) >= pr && (n - i) <= nx) {
      cnt = n - i;
      break;
    }
    pr *= 10;
    nx *= 10;
    nx += 9;
  }
  int tcnt = cnt;
  while (tcnt) {
    num[tcnt % 10]--;
    tcnt /= 10;
  }
  int first = b[0] - '0', second = 10;
  for (int i = 0; i < b.size(); ++i) {
    num[b[i] - '0']--;
    if ((b[i] - '0') != first && second == 10) second = (b[i] - '0');
  }
  res1 += b;
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < num[i]; ++j) res1 += '0' + i;
  int flag = 0, t = -1;
  for (int j = 1; j < 10; ++j) {
    if (num[j]) {
      t = j;
      break;
    }
  }
  int nx = t;
  if (num[0]) nx = 0;
  if (t == -1) {
    res2 += b;
    flag = 1;
  } else {
    res2 += t + '0';
    num[t]--;
  }
  for (;;) {
    int t = -1;
    for (int j = 0; j < 10; ++j) {
      if (num[j]) {
        t = j;
        break;
      }
    }
    if (t == -1) break;
    if ((!flag && (first < t || (first == t && second < t)))) {
      res2 += b;
      flag = 1;
    } else {
      res2 += t + '0';
      num[t]--;
    }
  }
  if (!flag) res2 += b;
  if (b[0] != '0')
    cout << min(res1, res2);
  else
    cout << res2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  srand(1313);
  solve();
  return 0;
}
