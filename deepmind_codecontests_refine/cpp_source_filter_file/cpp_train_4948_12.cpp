#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int a[N], b[N];
vector<int> v, v2;
int main() {
  int n;
  cin >> n;
  int st = 0, st2;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == n - 1) st = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (b[i] == n - 1) st2 = i;
  }
  for (int i = st;; i++) {
    if (a[i]) v.push_back(a[i]);
    if (i + 1 == n) i = -1;
    if (i == st - 1) break;
  }
  for (int j = st2;; j++) {
    if (b[j]) v2.push_back(b[j]);
    if (j + 1 == n) j = -1;
    if (j == st2 - 1) break;
  }
  for (int i = 0; i < n; i++)
    if (v[i] != v2[i]) return cout << "NO" << endl, 0;
  cout << "YES" << endl;
}
