#include <bits/stdc++.h>
using namespace std;
void solve() {
  char c;
  int pls = 0, mns = 0;
  vector<int> v;
  cin >> c;
  if (c == '-') {
    mns++;
    v.push_back(-1);
  } else {
    pls++;
    v.push_back(1);
  }
  while (c != '=') {
    cin >> c;
    if (c == '-') {
      mns++;
      v.push_back(-1);
    }
    if (c == '+') {
      pls++;
      v.push_back(1);
    }
  }
  int n;
  cin >> n;
  int mn = 1 * pls - (n * mns);
  int mx = n * pls - (1 * mns);
  if ((mn > n) or (mx < n)) {
    cout << "Impossible"
         << "\n";
    return;
  }
  cout << "Possible"
       << "\n";
  int q = pls - mns;
  q = n - q;
  int sz = v.size();
  if (q > 0) {
    for (int i = 0; i < sz; i++) {
      if (v[i] > 0) {
        if ((q + v[i]) >= n) {
          q = q + v[i] - n;
          v[i] = n;
        } else {
          v[i] = v[i] + q;
          q = 0;
        }
      }
    }
  } else if (q < 0) {
    for (int i = 0; i < sz; i++) {
      if (v[i] < 0) {
        if ((q + v[i]) >= -n) {
          q = q + v[i] + n;
          v[i] = -n;
        } else {
          v[i] = v[i] + q;
          q = 0;
        }
      }
    }
  }
  if (v[0] > 0)
    cout << v[0] << " ";
  else
    cout << "- " << abs(v[0]) << " ";
  for (int i = 1; i < sz; i++) {
    if (v[i] > 0) cout << "+ " << v[i] << " ";
    if (v[i] < 0) cout << "- " << abs(v[i]) << " ";
  }
  cout << "= " << n << "\n";
}
int main() {
  cin.tie(0);
  cout.tie(0);
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  int TC = 1;
  for (int ZZ = 1; ZZ <= TC; ZZ++) {
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds"
         << '\n';
  }
  return 0;
}
