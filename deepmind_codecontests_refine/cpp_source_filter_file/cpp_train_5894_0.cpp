#include <bits/stdc++.h>
using namespace std;
const int N = 3 * 100 * 1000 + 3, LG = 2;
int n, m, change;
bool mark[N];
int child[N * LG][2], val[N * LG], nxtNode = 1;
bool getBit(int x, int pos) { return x & (1 << pos); }
void addPath(int x) {
  int v = 0;
  for (int i = LG; i >= 0; i--) {
    val[v]++;
    if (!child[v][getBit(x, i)]) child[v][getBit(x, i)] = nxtNode++;
    v = child[v][getBit(x, i)];
  }
  val[v]++;
}
int getMex() {
  int v = 0, mex = 0;
  for (int i = LG; i >= 0; i--) {
    if (!child[v][getBit(change, i)]) return (mex << i);
    if (val[child[v][getBit(change, i)]] == (1 << i))
      if (!child[v][1 - getBit(change, i)])
        return (mex << (i + 1)) + (1 << i);
      else {
        v = child[v][1 - getBit(change, i)];
        mex = (mex << 1) + 1;
      }
    else {
      v = child[v][getBit(change, i)];
      mex <<= 1;
    }
  }
  return mex;
}
void input() {
  cin >> n >> m;
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    if (!mark[tmp]) {
      addPath(tmp);
      mark[tmp] = true;
    }
  }
}
void output() {
  int x = 0;
  for (int i = 0; i < m; i++) {
    cin >> x;
    change ^= x;
    cout << (getMex()) << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  input();
  output();
  return 0;
}
