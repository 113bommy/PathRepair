#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int a[200000];
int cnt[200000];
int main() {
  int c;
  scanf("%d", &c);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  std::vector<int> b;
  int pt = 0;
  while (pt < n) {
    int pn = pt + 1;
    while (pn < n && a[pn] == a[pt]) pn++;
    b.push_back(a[pt]);
    cnt[a[pt]] = pn - pt;
    pt = pn;
  }
  for (int add = 1; add < c; add++) {
    int cur = c;
    int def = add;
    int last = n - 1;
    while (cur > 0) {
      auto it = upper_bound((b).begin(), (b).end(), cur);
      int ind = it - b.begin() - 1;
      ind = min(ind, last);
      if (ind == -1 && cur != def) {
        cout << add;
        return 0;
      }
      if (def >= b[ind] && cur >= def) {
        cur -= def;
        def = 0;
      } else {
        int st = min(cur / b[ind], cnt[b[ind]]);
        cur -= st * b[ind];
        last = ind - 1;
      }
    }
  }
  cout << "Greed is good";
}
