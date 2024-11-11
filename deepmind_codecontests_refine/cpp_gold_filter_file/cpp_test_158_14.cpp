#include <bits/stdc++.h>
std::mt19937 rng(
    (unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
void solve(int ttt) {
  long long int n, m;
  cin >> n >> m;
  vector<long long int> x(n);
  for (long long int i = 0; i < n; i++) cin >> x[i];
  vector<vector<int> > a(n, vector<int>(m));
  for (long long int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (long long int j = 0; j < m; j++) {
      if (s[j] == '1')
        a[i][j] = 1;
      else
        a[i][j] = 0;
    }
  }
  long long int res = LLONG_MIN;
  vector<long long int> perm;
  for (int msk = 0; msk < (1 << n); msk++) {
    vector<int> coeff(m, 0);
    long long int curVal = 0;
    for (long long int i = 0; i < n; i++) {
      if (msk & (1 << i)) {
        curVal += x[i];
        for (long long int j = 0; j < m; j++) {
          if (a[i][j]) coeff[j]--;
        }
      } else {
        curVal -= x[i];
        for (long long int j = 0; j < m; j++) {
          if (a[i][j]) coeff[j]++;
        }
      }
    }
    vector<int> ind(m);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(),
         [&](int i, int j) { return coeff[i] < coeff[j]; });
    long long int c = 1;
    for (auto i : ind) {
      curVal += c * coeff[i];
      c++;
    }
    if (res < curVal) {
      res = curVal;
      vector<long long int> tmp(m);
      for (long long int i = 0; i < m; i++) {
        tmp[ind[i]] = i + 1;
      }
      swap(perm, tmp);
    }
  }
  for (long long int i = 0; i < m; i++) {
    cout << perm[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ttt;
  ttt = 1;
  cin >> ttt;
  for (long long int i = 0; i < ttt; i++) solve(i);
}
