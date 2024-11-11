#include <bits/stdc++.h>
using namespace std;
long long int check[2000005];
long long int funcg(long long int n) {
  if (n < 10)
    return n;
  else {
    long long int p = 1;
    long long int sum = 0;
    while (n) {
      int r = n % 10;
      if (r != 0) p = p * r;
      n = n / 10;
    }
    if (check[p] == 0)
      funcg(p);
    else {
      return (check[p]);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i < 2000005; i++) check[i] = 0;
  long long int q;
  cin >> q;
  long long int l[q], r[q], k[q];
  long long int min = 999999999;
  long long int max = 0;
  for (long long int i = 0; i < q; i++) {
    cin >> l[i] >> r[i] >> k[i];
    if (l[i] < min) min = l[i];
    if (r[i] > max) max = r[i];
  }
  long long int first = min;
  long long int last = max;
  vector<pair<long long int, long long int> > v[10];
  int j = 0;
  for (long long int i = first; i <= last; i++) {
    check[i] = funcg(i);
    v[check[i]].push_back(make_pair(i, v[check[i]].size() + 1));
  }
  for (long long int i = 0; i < q; i++) {
    long long int s = l[i];
    long long int e = r[i];
    long long int k1 = k[i];
    long long int n1 = v[k1].size();
    long long int c1 = 0;
    long long int f1 = 0;
    long long int l1 = n1 - 1;
    long long int mid = (f1 + l1) / 2;
    while (f1 <= l1) {
      if (v[k1][mid].first >= s) {
        l1 = mid - 1;
      } else {
        f1 = mid + 1;
      }
      mid = (f1 + l1) / 2;
    }
    int ans1 = f1;
    f1 = 0;
    l1 = n1 - 1;
    mid = (f1 + l1) / 2;
    while (f1 <= l1) {
      if (v[k1][mid].first <= e) {
        f1 = mid + 1;
      } else {
        l1 = mid - 1;
      }
      mid = (f1 + l1) / 2;
    }
    int ans2 = l1;
    if (ans2 < ans1)
      cout << 0 << endl;
    else
      cout << ans2 - ans1 + 1 << endl;
  }
}
