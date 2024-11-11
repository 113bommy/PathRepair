#include <bits/stdc++.h>
using namespace std;
int n, a[100005], nxt[100005];
vector<int> pos;
set<int> s;
long long ans;
bool isLucky(int x) {
  for (; x > 0; x /= 10)
    if (x % 10 != 4 && x % 10 != 7) return false;
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  pos.push_back(-1);
  for (int i = 0; i < n; i++)
    if (isLucky(a[i])) pos.push_back(i);
  for (int i = 1; i < pos.size(); i++) {
    nxt[i] = pos.size();
    for (int j = i + 1; j < pos.size(); j++)
      if (a[pos[i]] == a[pos[j]]) {
        nxt[i] = j;
        break;
      }
  }
  long long ans =
      ((((((n + 2) * 1ll * (n + 1)) / 2) * 1ll * n) / 3) * 1ll * (n - 1)) / 4;
  for (int i = 1; i < pos.size() - 1; i++) {
    s.clear();
    s.insert(pos[i]);
    s.insert(n);
    long long cr = 0ll;
    int dst = pos[i + 1] - pos[i];
    for (int j = i; j > 0; j--) {
      if (nxt[j] > i) {
        for (int k = nxt[j]; k < pos.size(); k = nxt[k]) {
          set<int>::iterator lf, rg;
          lf = rg = s.insert(pos[k]).first;
          lf--;
          rg++;
          if (lf == s.begin())
            cr +=
                (*rg - pos[k]) * 1ll *
                (dst * 1ll * (dst + 1) / 2 + (pos[k] - pos[i + 1]) * 1ll * dst);
          else
            cr += (*rg - pos[k]) * 1ll * (pos[k] - *lf) * 1ll * dst;
        }
      }
      ans -= cr * 1ll * (pos[j] - pos[j - 1]);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
