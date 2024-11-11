#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int K = 20;
int no;
bool h[N];
int t[N * K][2];
void ins(int x) {
  int c = 0;
  for (int i = K - 1; i >= 0; --i) {
    bool p = x >> i & 1;
    if (!t[c][p]) {
      t[c][p] = ++no;
    }
    c = t[c][p];
  }
}
int rep(int x) {
  int c = 0, res = 0;
  for (int i = K - 1; i >= 0; --i) {
    bool p = x >> i & 1;
    if (t[c][p]) {
      c = t[c][p];
    } else {
      res += 1 << i;
      c = t[c][p ^ 1];
    }
  }
  return res;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    h[x] = 1;
  }
  for (int i = 0; i <= 3e5; ++i) {
    if (!h[i]) {
      ins(i);
    }
  }
  int xo = 0;
  while (m--) {
    int x;
    cin >> x;
    xo ^= x;
    cout << rep(xo) << endl;
  }
}
