#include <bits/stdc++.h>
using namespace std;
map<long long, long long> s;
long long n, b[500005], c[500005];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    s[x]++;
  }
  long long m, mx1 = 0, mx2 = 0, index = 1;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < m; i++) {
    if (s[b[i]] > mx1) {
      mx1 = s[b[i]];
      index = i + 1;
    }
  }
  for (int i = 0; i < m; i++) {
    if (s[b[i]] == mx1) {
      if (s[c[i]] > mx2) {
        index = i + 1;
        mx2 = s[c[i]];
      }
    }
  }
  cout << index << endl;
  return 0;
}
