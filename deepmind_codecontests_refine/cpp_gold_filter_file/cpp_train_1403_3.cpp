#include <bits/stdc++.h>
using namespace std;
struct order {
  int num;
  int pos;
};
bool fun(order a, order b) { return (a.num < b.num); }
int main() {
  int n, k, i, j;
  cin >> n >> k;
  vector<order> a(n);
  for (i = 0; i < n; i++) {
    cin >> a[i].num;
    a[i].pos = i + 1;
  }
  set<int> s;
  sort(a.begin(), a.end(), fun);
  i = 0;
  while (k - a[i].num >= 0 && i < n) {
    k -= a[i].num;
    s.insert(a[i].pos);
    i++;
  }
  cout << s.size() << endl;
  set<int>::iterator it;
  for (it = s.begin(); it != s.end(); it++) cout << *it << "  ";
  return 0;
}
