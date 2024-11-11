#include <bits/stdc++.h>
using namespace std;
const int inf = 10000000;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> r(n, -1);
    int bandas = 0;
    vector<int> banda(n + 1, -1);
    vector<set<pair<int, int> > > bandahas(n + 1);
    for (int i = n - 2; i >= 0; --i) {
      if (a[i + 1] == a[i]) {
        if (i + 2 < n && banda[a[i + 2]] != -1)
          banda[i] = banda[i + 2];
        else
          banda[i] = ++bandas;
        r[i] = i + 1;
      } else {
        if (banda[i + 1] != -1) {
          auto it = bandahas[banda[i + 1]].lower_bound(make_pair(a[i], -1));
          if (it != bandahas[banda[i + 1]].end() && it->first == a[i]) {
            r[i] = it->second;
            if (r[i] + 1 < n && banda[r[i] + 1] != -1)
              banda[i] = banda[r[i] + 1];
            else
              banda[i] = ++bandas;
          }
        }
      }
      if (banda[i] != -1 && r[i] + 1 < n) {
        auto it = bandahas[banda[i]].lower_bound(make_pair(a[r[i] + 1], -1));
        if (it != bandahas[banda[i]].end() && it->first == a[r[i] + 1])
          bandahas[banda[i]].erase(it);
        bandahas[banda[i]].insert(make_pair(a[r[i] + 1], r[i] + 1));
      }
    }
    vector<int> used(n, 0);
    long long fullans = 0;
    for (int i = 0; i < n; ++i)
      if (!used[i]) {
        long long num = 0;
        int j = i;
        while (true) {
          if (j >= n || r[j] == -1) break;
          ++num;
          used[j] = true;
          j = r[j] + 1;
        }
        fullans += ((num * (num + 1LL)) / 2LL);
      }
    cout << fullans << '\n';
  }
}
