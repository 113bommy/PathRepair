#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long N = 1e5 + 5;
long long a[N];
long long ps[N];
int main() {
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 1; i < n; i++) {
    ps[i] = ps[i - 1];
    if (s[i - 1] == '.') ps[i]++;
  }
  int m;
  cin >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    cout << ps[r] - ps[l] << endl;
  }
  return 0;
}
