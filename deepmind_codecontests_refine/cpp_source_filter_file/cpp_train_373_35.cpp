#include <bits/stdc++.h>
using namespace std;
struct segment_tree {
  long long a[1 << 20][5];
  int sz[1 << 20];
  int N;
  void initi(int x) {
    N = 1;
    while (N < x) N <<= 1;
  }
  void pushup(int x) {
    int pos = x + N - 1;
    while (x > 0) {
      x = (x - 1) >> 1;
      sz[x] = sz[(x << 1) + 1] + sz[(x << 1) + 2];
      for (int i = 0; i < 5; i++) a[x][i] = 0;
      for (int i = 0; i < 5; i++) {
        a[x][i] += a[(x << 1) + 1][i];
        a[x][(i + sz[(x << 1) + 1]) % 5] += a[(x << 1) + 2][i];
      }
    }
  }
  void ins(int x, int y) {
    int pos = x + N - 1;
    sz[pos]++;
    a[pos][0] = y;
    pushup(pos);
  }
  void del(int x) {
    int pos = x / 5 + N - 1;
    sz[pos]--;
    a[pos][0] = 0;
    pushup(pos);
  }
} tr;
int n;
int s[100010];
vector<int> v;
vector<int> vc;
map<int, int> mp;
int l;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string t;
    int x;
    cin >> t;
    if (t == "add") {
      cin >> x;
      v.push_back(x);
      vc.push_back(x);
    } else if (t == "del") {
      cin >> x;
      v.push_back(-x);
    } else {
      v.push_back(0);
    }
  }
  sort(vc.begin(), vc.end());
  tr.initi((int)vc.size());
  for (int i = 0; i < vc.size(); i++) {
    mp[vc[i]] = i;
  }
  for (int i = 0; i < v.size(); i++) {
    if (!v[i]) {
      printf("%lld\n", tr.a[0][2]);
    } else if (v[i] < 0) {
      tr.del(mp[-v[i]]);
    } else {
      tr.ins(mp[v[i]], v[i]);
    }
  }
  return 0;
}
