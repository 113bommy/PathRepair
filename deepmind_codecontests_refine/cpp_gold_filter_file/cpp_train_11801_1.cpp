#include <bits/stdc++.h>
using namespace std;
int ans, n;
vector<int> vec;
int nxt[500005][20];
int porer[500005], ins;
bool go(int pos, int msk, int inver) {
  ins++;
  if (ins > 100000000) return true;
  if (inver >= ans || (porer[pos] & msk) != msk) return false;
  if (!msk) {
    ans = min(ans, inver);
    return true;
  }
  if (pos >= vec.size()) return false;
  int c = n - __builtin_popcount(msk), pp = 0;
  for (int i = 0; i < n; i++) {
    if (msk & (1 << i)) {
      if (go(nxt[pos][i] + 1, msk ^ (1 << i), inver + c)) {
        pp++;
        if (pp > 1) return true;
      }
    } else
      c--;
  }
  return false;
}
vector<string> all;
char str[25];
map<string, int> ID;
bool do_it(int p) {
  if (vec.size() < 2 * p) return false;
  int sz = vec.size();
  for (int i = 1; i <= p; i++)
    if (vec[sz - i] != vec[sz - i - p]) return false;
  while (p--) vec.pop_back();
  return true;
}
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", str);
    all.push_back(str);
  }
  for (i = 0; i < all.size(); i++) ID[all[i]] = i;
  int mx = (n * (n - 1)) / 2 + 1, m;
  scanf("%d", &m);
  int final_ans = mx, ww;
  ans = mx;
  for (int t = 0; t < m; t++) {
    int k;
    scanf("%d", &k);
    vec.clear();
    for (j = 0; j < k; j++) {
      scanf("%s", str);
      if (ID.find(str) == ID.end()) continue;
      int wh = ID[str];
      if (vec.size() == 0 || vec[vec.size() - 1] != wh) vec.push_back(wh);
      for (int p = 205; p > 1; p--) do_it(p);
      if (vec.size() >= 3) {
        int sz = vec.size();
        if (vec[sz - 1] == vec[sz - 3] && vec[sz - 2] > vec[sz - 1])
          vec.pop_back();
      }
    }
    porer[vec.size()] = 0;
    for (i = vec.size() - 1; i >= 0; i--)
      porer[i] = (porer[i + 1] | (1 << vec[i]));
    for (i = 0; i < n; i++) nxt[vec.size()][i] = 1000000000;
    for (i = vec.size() - 1; i >= 0; i--) {
      for (j = 0; j < n; j++) nxt[i][j] = nxt[i + 1][j];
      nxt[i][vec[i]] = i;
    }
    go(0, (1 << n) - 1, 0);
    if (ans < final_ans) {
      final_ans = ans;
      ww = t;
    }
  }
  if (final_ans == mx)
    printf("Brand new problem!\n");
  else {
    final_ans = (n * (n - 1)) / 2 - final_ans + 1;
    printf("%d\n", ww + 1);
    printf("[:");
    for (i = 0; i < final_ans; i++) printf("|");
    printf(":]\n");
  }
  return 0;
}
