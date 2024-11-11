#include <bits/stdc++.h>
using namespace std;
set<int> H;
set<int>::iterator it;
int ind[1000666], a[1000666], b[1000666], k;
int i, Arb[1000666], n;
bool fr[1000666];
long long result;
void update(int pos) {
  for (; pos <= n; pos += (pos & (pos ^ (pos - 1)))) Arb[pos]++;
}
int query(int pos) {
  int res = 0;
  for (; pos > 0; pos -= (pos & (pos ^ (pos - 1)))) res += Arb[pos];
  return res;
}
bool comp(int i1, int i2) { return a[i1] < a[i2]; }
int main() {
  cin >> n >> k;
  for (i = 1; i <= n; ++i) {
    cin >> a[i];
    ind[i] = i;
  }
  for (i = 1; i <= n; ++i) {
    cin >> b[i];
    fr[b[i]] = true;
  }
  sort(ind + 1, ind + n + 1, comp);
  for (i = 1; i <= n; ++i) {
    int ls, ld;
    if (fr[a[ind[i]]] == true) {
      H.insert(ind[i]);
      continue;
    }
    update(ind[i]);
    if (H.empty() == true) {
      result += n - query(n) + 1;
      continue;
    }
    it = H.lower_bound(ind[i]);
    if (it == H.end()) {
      ld = n;
      ls = (*(--it)) + 1;
    } else if (it == H.begin()) {
      ls = 1;
      ld = (*it) - 1;
    } else {
      ld = (*it) - 1;
      ls = (*(--it)) + 1;
    }
    result += (long long)((ld - ls + 1) - query(ld) + query(ls - 1) + 1);
  }
  cout << result << '\n';
  return 0;
}
