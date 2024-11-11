#include <bits/stdc++.h>
#pragma GCC optimize("-ffloat-store")
using namespace std;
template <typename T>
ostream &operator<<(ostream &out, vector<T> v) {
  for (T t : v) out << t << ' ';
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, set<T> v) {
  for (T t : v) out << t << ' ';
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, pair<T, T> v) {
  out << v.F << ' ' << v.S;
  return out;
}
string ss = "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
int a[107][107], temp[107][107];
char ans[107][107];
int r, c, k, t;
string s;
pair<int, int> dir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
pair<int, int> pluss(pair<int, int> x, pair<int, int> y) {
  return {x.first + y.first, x.second + y.second};
}
vector<pair<int, int> > convert(int r, int c) {
  vector<pair<int, int> > ans;
  for (long long i = 1; i <= r; i++) {
    for (long long j = 1; j <= c; j++) {
      temp[i][j] = 0;
    }
  }
  for (long long i = 0; i <= c + 1; i++) {
    temp[0][i] = temp[r + 1][i] = 1;
  }
  for (long long i = 0; i <= r + 1; i++) {
    temp[i][0] = temp[i][c + 1] = 1;
  }
  pair<int, int> cur = {1, 1};
  int d = 0;
  for (long long i = 1; i <= r * c; i++) {
    ans.push_back(cur);
    temp[cur.first][cur.second] = 1;
    if (i == r * c) break;
    pair<int, int> nxt = pluss(cur, dir[d]);
    if (temp[nxt.first][nxt.second] == 0) {
      cur = nxt;
    } else {
      d++;
      d %= 4;
      cur = pluss(cur, dir[d]);
    }
  }
  return ans;
}
void oneTest() {
  cin >> r >> c >> k;
  int cnt = 0;
  for (long long i = 1; i <= r; i++) {
    cin >> s;
    for (long long j = 1; j <= c; j++) {
      if (s[j - 1] == 'R') {
        a[i][j] = true;
        cnt++;
      } else {
        a[i][j] = false;
      }
    }
  }
  int tb = cnt / k;
  vector<int> value;
  for (long long i = 1; i <= cnt % k; i++) {
    value.push_back(tb + 1);
  }
  while (value.size() < k) {
    value.push_back(tb);
  }
  vector<pair<int, int> > v = convert(r, c);
  int ind = 0;
  int cnttt = 0;
  for (pair<int, int> &e : v) {
    if (a[e.first][e.second]) {
      cnttt++;
    }
    ans[e.first][e.second] = ss[ind];
    if (cnttt >= value[ind] && ind < k - 1) {
      ind++;
      cnttt = 0;
    }
  }
  for (long long i = 1; i <= r; i++) {
    for (long long j = 1; j <= c; j++) {
      cout << ans[i][j];
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    oneTest();
  }
}
