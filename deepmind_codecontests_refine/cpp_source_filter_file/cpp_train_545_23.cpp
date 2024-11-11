#include <bits/stdc++.h>
using namespace std;
const int N = 100009;
int n;
long long a[N];
void print_ans(int l, int r, vector<long long>& v) {
  cout << l << ' ' << r << '\n';
  for (int vv : v) {
    cout << vv << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<long long> fst;
  fst.push_back(-a[0]);
  a[0] = 0;
  print_ans(1, 1, fst);
  if (n == 1) {
    vector<long long> zero = {0};
    print_ans(1, 1, zero);
    print_ans(1, 1, zero);
    return 0;
  }
  vector<long long> scd;
  for (int i = 1; i < n; ++i) {
    long long md = a[i] % n;
    if (md < 0) md += n;
    long long nm = md * (n - 1);
    scd.push_back(nm);
    a[i] += nm;
  }
  print_ans(2, n, scd);
  vector<long long> all;
  for (int i = 0; i < n; ++i) {
    assert(a[i] % n == 0);
    all.push_back(-a[i]);
  }
  print_ans(1, n, all);
  return 0;
}
