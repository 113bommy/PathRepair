#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000200];
int inv[1000200];
std::vector<int> v;
struct node {
  int st, en, ind;
};
node aa[1002020];
bool cmp(node a, node b) {
  if (a.en != b.en) return a.en < b.en;
  return a.st < b.st;
}
int ans[1000202], bit[1000202];
map<int, int> last;
void update(int ind, int value) {
  while (ind <= 1000000) {
    bit[ind] ^= value;
    ind = ind + (ind & (-ind));
  }
}
int query(int x) {
  int ret = 0;
  while (x > 0) {
    ret ^= bit[x];
    x = x - (x & (-x));
  }
  return ret;
}
int cumuxor[1000202];
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    cumuxor[i] = (a[i] ^ cumuxor[i - 1]);
  }
  int q;
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    int st, en;
    scanf("%d %d", &st, &en);
    aa[i] = (node){st, en, i};
  }
  sort(aa, aa + q, cmp);
  int endit = 1;
  for (i = 0; i < q; i++) {
    int starting, ending;
    starting = aa[i].st;
    ending = aa[i].en;
    while (endit <= ending) {
      if (last[a[endit]] > 0) {
        int parahai = (last[a[endit]]);
        update(parahai, a[endit]);
      }
      update(endit, a[endit]);
      last[a[endit]] = endit;
      endit++;
    }
    ans[aa[i].ind] = (query(ending) ^ query(starting - 1)) ^
                     (cumuxor[ending] ^ cumuxor[starting - 1]);
  }
  for (i = 0; i < q; ++i) printf("%d\n", ans[i]);
  return 0;
}
