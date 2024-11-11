#include <bits/stdc++.h>
using namespace std;
int inf = 1000000009;
int f(int x) {
  int sum = 0, i = 0;
  while (sum < x) sum += i, ++i;
  --i;
  if (sum > x) --i;
  return i;
}
int c[100005] = {};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k, l, p, a, b;
  vector<int> d1, d2;
  cin >> a >> b;
  int err = 0;
  int kol = f(a + b);
  if (a > b) swap(a, b), err = 1;
  int i;
  for (i = min(kol, a); i > 0; i--) {
    if (i > a) break;
    a -= i;
    d1.push_back(i);
    c[i] = 1;
  }
  if (a) d1.push_back(a), c[a] = 1;
  a = 0;
  for (int i = 1; i <= kol; i++)
    if (!c[i]) {
      if (i > b) break;
      c[i] = 1;
      d2.push_back(i);
      b -= i;
    }
  if (!err) {
    cout << d1.size() << endl;
    for (int i = 0; i < d1.size(); i++) cout << d1[i] << " ";
    if (d1.size()) cout << endl;
    cout << d2.size() << endl;
    for (int i = 0; i < d2.size(); i++) cout << d2[i] << " ";
  } else {
    cout << d2.size() << endl;
    for (int i = 0; i < d2.size(); i++) cout << d2[i] << " ";
    if (d2.size()) cout << endl;
    cout << d1.size() << endl;
    for (int i = 0; i < d1.size(); i++) cout << d1[i] << " ";
  }
}
