#include <bits/stdc++.h>
using namespace std;
struct _ {
  _() { ios_base::sync_with_stdio(0); }
} _;
template <class A, class B>
ostream &operator<<(ostream &o, pair<A, B> t) {
  o << "(" << t.first << ", " << t.second << ")";
  return o;
}
template <class T>
string tostring(T first, int len = 0, char c = '0') {
  stringstream ss;
  ss << first;
  string r = ss.str();
  if (r.length() < len) r = string(len - r.length(), c) + r;
  return r;
}
template <class T>
void PV(T a, T b, int n = 0, int w = 0, string s = " ") {
  int c = 0;
  while (a != b) {
    cout << tostring(*a++, w, ' ');
    if (a != b && (n == 0 || ++c % n))
      cout << s;
    else
      cout << endl;
  }
}
template <class T>
inline bool chmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool chmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
const long long linf = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 1 << 19;
int dx[6] = {1, 0, -1, 1, 0, -1};
int dy[6] = {1, 2, 1, -1, -2, -1};
int a[19];
int nxt[19][6];
int b[5][9];
int id[5][9];
pair<int, int> rd[19];
int sg[N];
int main() {
  for (int i = 0; i < 5; i++) {
    if (i == 0 || i == 4) {
      for (int j = 2; j <= 6; j += 2) b[i][j] = 1;
    }
    if (i == 1 || i == 3) {
      for (int j = 1; j <= 7; j += 2) b[i][j] = 1;
    }
    if (i == 2) {
      for (int j = 0; j <= 8; j += 2) b[i][j] = 1;
    }
  }
  memset(id, -1, sizeof(id));
  ;
  int cnt = 0;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 9; j++) {
      if (b[i][j]) {
        id[i][j] = cnt;
        rd[cnt] = make_pair(i, j);
        cnt++;
      }
    }
  memset(nxt, -1, sizeof(nxt));
  ;
  for (int i = 0; i < 19; i++) {
    int first = rd[i].first;
    int second = rd[i].second;
    for (int j = 0; j < 6; j++) {
      int nx = rd[i].first + dx[j];
      int ny = rd[i].second + dy[j];
      if (nx >= 0 && nx < 5 && ny >= 0 && ny < 9 && b[nx][ny]) {
        nxt[i][j] = id[nx][ny];
      }
    }
  }
  bitset<20> mex;
  for (int i = 0; i <= 19; i++) {
    for (int j = 0; j < 1 << 19; j++) {
      if (bitset<30>(j).count() != i) continue;
      mex.reset();
      for (int k = 0; k < 19; k++) {
        if (!(j >> k & 1)) continue;
        for (int first = 0; first < 6; first++) {
          int mask = j;
          int second = k;
          while (1) {
            mask ^= 1 << second;
            mex[sg[mask]] = 1;
            second = nxt[second][first];
            if (second == -1 || !(j >> second & 1)) break;
          }
        }
      }
      int p = 0;
      while (mex[p] != 0) p++;
      sg[j] = p;
    }
  }
  int in = 0;
  for (int i = 0; i < 19; i++) {
    char c;
    cin >> c;
    if (c == 'O') {
      in |= 1 << i;
    }
  }
  cout << (sg[in] ? "Karlsson" : "Lillebror") << endl;
  return 0;
}
