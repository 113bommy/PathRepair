#include <bits/stdc++.h>
using namespace std;
int nxt() {
  int x;
  cin >> x;
  return x;
}
int main() {
  int n = nxt();
  vector<int> a(n);
  generate(a.begin(), a.end(), nxt);
  int mx = *max_element(a.begin(), a.end());
  vector<int> p(mx + 1, n - 1);
  for (int i = 0; i < int(n); ++i) p[a[i]] = i;
  int ans = n - 1;
  for (int i = 0; i < int(mx + 1); ++i) {
    if (p[i] < ans) {
      ans = p[i];
    }
  }
  cout << a[ans] << '\n';
  return 0;
}
