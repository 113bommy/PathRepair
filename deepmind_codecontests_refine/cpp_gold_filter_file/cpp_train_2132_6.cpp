#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, long long>;
bool FindMatch(long long i, const vector<vector<long long> > &w,
               vector<long long> &mr, vector<long long> &mc,
               vector<long long> &seen) {
  for (long long j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}
long long BipartiteMatching(const vector<vector<long long> > &w,
                            vector<long long> &mr, vector<long long> &mc) {
  mr = vector<long long>(w.size(), -1);
  mc = vector<long long>(w[0].size(), -1);
  long long ct = 0;
  for (long long i = 0; i < w.size(); i++) {
    vector<long long> seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}
vector<long long> hat(2 * 1e4 + 1, -1);
bool prime(long long a) {
  if (hat[a] != -1) return hat[a];
  for (long long i = 2; i * i <= a; i++) {
    if (a % i == 0) return hat[a] = 0;
  }
  return hat[a] = 1;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> c(n);
  vector<pair<long long, long long> > a;
  vector<pair<long long, long long> > b;
  for (long long i = 0; i < n; i++) {
    long long temp;
    cin >> c[i];
    temp = c[i];
    if (temp % 2 == 0)
      a.push_back({temp, i});
    else
      b.push_back({temp, i});
  }
  vector<vector<long long> > adi(a.size(), vector<long long>(b.size()));
  for (long long i = 0; i < a.size(); i++) {
    for (long long j = 0; j < b.size(); j++) {
      if (prime(a[i].first + b[j].first)) {
        adi[i][j] = 1;
      }
    }
  }
  vector<long long> seen(n);
  vector<long long> row;
  vector<long long> col;
  auto res = BipartiteMatching(adi, row, col);
  for (long long i = 0; i < row.size() && 2 * res == n; i++) {
    if (adi[i][row[i]] == 0) res--;
    adi[i][row[i]] = 0;
  }
  for (long long i = 0; i < col.size() && 2 * res == n; i++) {
    adi[col[i]][i] = 0;
  }
  vector<long long> c2, r2;
  auto re2 = BipartiteMatching(adi, r2, c2);
  if (re2 + res != n) {
    cout << "Impossible\n";
  } else {
    vector<vector<long long> > tab;
    vector<long long> hat_a(a.size());
    vector<long long> hat_b(b.size());
    for (long long i = 0; i < a.size(); i++) {
      if (hat_a[i]) continue;
      vector<long long> t;
      t.push_back(a[i].second);
      long long cura = i;
      long long curb = row[cura];
      t.push_back(b[curb].second);
      hat_a[cura] = 1;
      do {
        cura = c2[curb];
        curb = row[cura];
        hat_a[cura] = 1;
        t.push_back(a[cura].second);
        t.push_back(b[curb].second);
      } while (cura != i);
      tab.push_back(t);
    }
    cout << tab.size() << "\n";
    for (long long i = 0; i < tab.size(); i++) {
      cout << tab[i].size() - 2 << " ";
      for (long long j = 0; j < tab[i].size() - 2; j++)
        cout << tab[i][j] + 1 << " ";
      cout << "\n";
    }
  }
}
