#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  os << "{" << p.first << " " << p.second << "}";
  return os;
}
int main() {
  int n;
  cin >> n;
  n *= 3;
  vector<int> pl(n, 0), r_pl(n, 0), orig(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> pl[i];
    pl[i]--;
    r_pl[pl[i]] = i;
  }
  orig = pl;
  vector<int> a(n / 3, 0), b(n / 3, 0), c(n / 3, 0);
  for (int i = 0; i < n / 3; ++i) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--, b[i]--, c[i]--;
  }
  int k1;
  cin >> k1;
  k1--;
  int ind = 0;
  vector<vector<int> > ret(n, vector<int>());
  for (int i = 0; i < n / 3; ++i) {
    while (pl[ind] == -1) ind++;
    assert(ind < n);
    int curr = pl[ind];
    pl[r_pl[a[i]]] = -1;
    pl[r_pl[b[i]]] = -1;
    pl[r_pl[c[i]]] = -1;
    {
      int k = k1;
      vector<int> ret;
      if (k == a[i] || k == b[i] || k == c[i]) {
        int r1, r2;
        if (k == a[i]) r1 = b[i], r2 = c[i];
        if (k == b[i]) r1 = a[i], r2 = c[i];
        if (k == c[i]) r1 = b[i], r2 = a[i];
        if (k == curr) {
          for (int i = 0; i < n; ++i)
            if (i != k && (pl[r_pl[i]] == -1 && i <= max(r1, r2)))
              ret.push_back(i);
          for (int i = 0; i < n; ++i)
            if (i != k && !(pl[r_pl[i]] == -1 && i <= max(r1, r2)))
              ret.push_back(i);
        } else {
          for (int i = 0; i < n; ++i)
            if (i != k) ret.push_back(i);
        }
        {
          for (int i = 0; i < n - 1; ++i) cout << ret[i] + 1 << " ";
          cout << endl;
        }
        return 0;
      }
    }
  }
  return 0;
}
