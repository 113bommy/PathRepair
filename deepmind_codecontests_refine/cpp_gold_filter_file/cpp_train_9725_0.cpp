#include <bits/stdc++.h>
using namespace std;
inline void pisz(int n) { printf("%d\n", n); }
template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  for (int(i) = 0; (i) < (((int)((t).size()))); ++(i)) s << t[i] << " ";
  return s;
}
int a[400007], b[400007], cnt[400007], mabyc[400007];
int main() {
  int(n), (m), (p);
  scanf("%d %d %d", &(n), &(m), &(p));
  for (int(i) = 1; (i) <= (n); ++(i)) scanf("%d", a + i);
  for (int(i) = 1; (i) <= (m); ++(i)) scanf("%d", b + i);
  vector<int> sorter;
  for (int(i) = 1; (i) <= (n); ++(i)) sorter.push_back(a[i]);
  for (int(i) = 1; (i) <= (m); ++(i)) sorter.push_back(b[i]);
  sort(sorter.begin(), sorter.end());
  sorter.erase(unique(sorter.begin(), sorter.end()), sorter.end());
  for (int(i) = 1; (i) <= (n); ++(i))
    a[i] = lower_bound(sorter.begin(), sorter.end(), a[i]) - sorter.begin();
  for (int(i) = 1; (i) <= (m); ++(i))
    b[i] = lower_bound(sorter.begin(), sorter.end(), b[i]) - sorter.begin();
  int chce = 0;
  for (int(i) = 1; (i) <= (m); ++(i)) {
    if (0 == mabyc[b[i]]) ++chce;
    mabyc[b[i]]++;
  }
  vector<int> res;
  for (int(of) = 1; (of) <= (p); ++(of)) {
    if (of + 1LL * (m - 1) * p <= n) {
      vector<int> used;
      int dobro = 0;
      for (int(i) = 0; (i) < (m); ++(i)) {
        int j = of + i * p;
        if (mabyc[a[j]] == cnt[a[j]]) --dobro;
        cnt[a[j]]++;
        used.push_back(a[j]);
        if (mabyc[a[j]] == cnt[a[j]]) ++dobro;
      }
      if (dobro == chce) res.push_back(of);
      for (int q = of + p; q + 1LL * (m - 1) * p <= n; q += p) {
        int j = q - p;
        if (mabyc[a[j]] == cnt[a[j]]) --dobro;
        cnt[a[j]]--;
        if (mabyc[a[j]] == cnt[a[j]]) ++dobro;
        j = q + (m - 1) * p;
        if (mabyc[a[j]] == cnt[a[j]]) --dobro;
        cnt[a[j]]++;
        used.push_back(a[j]);
        if (mabyc[a[j]] == cnt[a[j]]) ++dobro;
        if (chce == dobro) res.push_back(q);
      }
      for (typeof(used.begin()) x = used.begin(); x != used.end(); x++)
        cnt[*x] = 0;
    }
  }
  sort(res.begin(), res.end());
  pisz(((int)((res).size())));
  for (typeof(res.begin()) x = res.begin(); x != res.end(); x++)
    printf("%d ", *x);
}
