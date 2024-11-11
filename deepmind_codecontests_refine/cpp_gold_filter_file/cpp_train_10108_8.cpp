#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline ostream& operator<<(ostream& os, const pair<A, B>& v) {
  return os << v.first << ' ' << v.second;
}
template <typename T>
inline ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto it = v.begin(); it != v.end(); os << (*it++))
    if (it != v.cbegin()) os << ' ';
  return os;
}
void _debug() {}
template <typename H, typename... T>
void _debug(H head, T... tail) {
  cerr << head;
  sizeof...(tail) ? cerr << ' ' : cerr << "]" << flush;
  _debug(tail...);
}
const int oo = 0x3f3f3f3f;
const long long mod = (long long)1e9 + 7;
void Main();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  Main();
  return 0;
}
int id[1000005];
int ch[1000005][2], a[1000005], ans[1000005];
void Main() {
  string s;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    if (s[0] == 'A') {
      cin >> (ch[i][0]);
      cin >> (ch[i][1]);
      id[i] = 1;
      continue;
    }
    if (s[0] == 'O') {
      cin >> (ch[i][0]);
      cin >> (ch[i][1]);
      id[i] = 2;
      continue;
    }
    if (s[0] == 'N') {
      cin >> (ch[i][0]);
      id[i] = 3;
      continue;
    }
    if (s[0] == 'I') {
      cin >> (a[i]);
      id[i] = 4;
      continue;
    }
    cin >> (ch[i][0]);
    cin >> (ch[i][1]);
    id[i] = 5;
  }
  function<void(int)> dfs = [&](int x) {
    if (id[x] <= 2 || id[x] == 5) {
      dfs(ch[x][0]);
      dfs(ch[x][1]);
      if (id[x] == 1) {
        a[x] = a[ch[x][0]] & a[ch[x][1]];
      } else if (id[x] == 2) {
        a[x] = a[ch[x][0]] | a[ch[x][1]];
      } else {
        a[x] = a[ch[x][0]] ^ a[ch[x][1]];
      }
    } else if (id[x] == 3) {
      dfs(ch[x][0]);
      a[x] = !a[ch[x][0]];
    }
  };
  dfs(1);
  98;
  function<void(int, int)> c = [&](int x, int ss) {
    if (id[x] == 1) {
      if (a[ch[x][0]] > a[ch[x][1]]) {
        swap(ch[x][0], ch[x][1]);
      }
      if (!a[ch[x][1]]) {
        c(ch[x][0], 0);
        c(ch[x][1], 0);
      } else if (!a[ch[x][0]] && a[ch[x][1]] == 1) {
        c(ch[x][0], ss);
        c(ch[x][1], 0);
      } else {
        for (int(i) = (0); (i) < (2); ++(i)) c(ch[x][i], ss);
      }
    } else if (id[x] == 2) {
      if (a[ch[x][0]] > a[ch[x][1]]) {
        swap(ch[x][0], ch[x][1]);
      }
      if (!a[ch[x][1]]) {
        c(ch[x][0], ss);
        c(ch[x][1], ss);
      } else if (!a[ch[x][0]] && a[ch[x][1]] == 1) {
        c(ch[x][0], 0);
        c(ch[x][1], ss);
      } else {
        for (int(i) = (0); (i) < (2); ++(i)) c(ch[x][i], 0);
      }
    } else if (id[x] == 3) {
      c(ch[x][0], ss);
    } else if (id[x] == 5) {
      for (int(i) = (0); (i) < (2); ++(i)) c(ch[x][i], ss);
    } else {
      ans[x] = ((ss == 1) ? a[1] : (a[1] ^ 1));
    }
  };
  c(1, 1);
  for (int i = 1; i <= n; ++i) {
    if (id[i] == 4) cout << (ans[i] ^ 1);
  }
  cout << endl;
}
