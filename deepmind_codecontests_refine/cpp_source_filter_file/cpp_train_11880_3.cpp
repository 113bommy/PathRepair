#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  vector<int> v;
  v.push_back(n);
  for (int i = 0; i < n - 1; i++) cin >> a[i];
  for (int i = n - 2; i >= 1;) {
    v.push_back(a[i]);
    i = a[i] - 2;
    if (i == 0) break;
  }
  int k = v.size();
  if (v[n - 1] != 1) v.push_back(1);
  sort(v.begin(), v.end());
  auto it = v.begin();
  for (; it != v.end(); it++) cout << *it << " ";
}
