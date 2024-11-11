#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2505, MAXM = 2505;
int N, M, Q;
long long a[MAXN][MAXM];
map<pair<pair<int, int>, pair<int, int> >, int> f;
inline int lowbit(int x) { return x & -x; }
void modify(int x, int y, int val) {
  while (x <= N) {
    for (int i = y; i <= M; i += lowbit(i)) a[x][i] ^= val;
    x += lowbit(x);
  }
}
int query(int x, int y) {
  int ans = 0;
  while (x) {
    for (int i = y; i; i -= lowbit(i)) ans ^= a[x][i];
    x -= lowbit(x);
  }
  return ans;
}
int myRand() { return (rand() << 15) | rand(); }
int main() {
  int t, r1, c1, r2, c2, v;
  srand(135792468);
  scanf("%d%d%d", &N, &M, &Q);
  while (Q--) {
    scanf("%d%d%d%d%d", &t, &r1, &c1, &r2, &c2);
    if (1 == t) {
      v = myRand();
      modify(r1, c1, v);
      modify(r1, c2 + 1, v);
      modify(r2 + 1, c1, v);
      modify(r2 + 1, c2 + 1, v);
      f[make_pair(make_pair(r1, c1), make_pair(r2, c2))] = v;
    } else if (2 == t) {
      v = f[make_pair(make_pair(r1, c1), make_pair(r2, c2))];
      modify(r1, c1, v);
      modify(r1, c2 + 1, v);
      modify(r2 + 1, c1, v);
      modify(r2 + 1, c2 + 1, v);
      f.erase(make_pair(make_pair(r1, c1), make_pair(r2, c2)));
    } else {
      int x = query(r1, c1), y = query(r2, c2);
      printf("%s\n", x == y ? "Yes" : "No");
    }
  }
  return 0;
}
