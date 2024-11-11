#include <bits/stdc++.h>
using namespace std;
int n;
char str[10010][10];
struct Hash {
  long long val, from, cnt;
};
Hash allms[800000];
Hash ans[800000];
int amsn = 0, ansn = 0;
bool cmp(const Hash &a, const Hash &b) { return a.val < b.val; }
void solve() {
  for (int i = 0; i < n; i++) {
    Hash set[500];
    int sn = 0;
    int len = strlen(str[i]);
    for (int j = 0; j < len; j++) {
      Hash hash;
      hash.val = 0;
      hash.from = i;
      for (int k = j; k < len; k++) {
        hash.val *= 123;
        hash.val += str[i][k];
        set[sn++] = hash;
      }
    }
    sort(set, set + sn, cmp);
    allms[amsn++] = set[0];
    for (int j = 1; j < sn; j++)
      if (set[j].val != set[j - 1].val) allms[amsn++] = set[j];
  }
  sort(allms, allms + amsn, cmp);
  for (int i = 0; i < amsn;) {
    ans[ansn] = allms[i];
    int j = i + 1, cnt = 1;
    for (; j < amsn && allms[j].val == allms[j - 1].val; j++, cnt++)
      ;
    ans[ansn++].cnt = cnt;
    i = j;
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> str[i];
  solve();
  int q;
  cin >> q;
  char query[10];
  long long qhash;
  for (int i = 0; i < q; i++) {
    cin >> query;
    qhash = 0;
    int len = strlen(query);
    for (int j = 0; j < len; j++) {
      qhash *= 123;
      qhash += query[j];
    }
    int left = 0, right = ansn - 1, mid;
    while (left < right - 1) {
      mid = (left + right) / 2;
      if (ans[mid].val < qhash)
        left = mid;
      else
        right = mid;
    }
    if (ans[left].val == qhash)
      cout << ans[left].cnt << ' ' << str[ans[left].from] << endl;
    else if (ans[right].val == qhash)
      cout << ans[right].cnt << ' ' << str[ans[right].from] << endl;
    else
      cout << "0 -" << endl;
  }
  return 0;
}
