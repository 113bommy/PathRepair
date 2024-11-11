#include <bits/stdc++.h>
using namespace std;
long long int s[100005] = {0}, m[100005];
int main() {
  long long int i, j, k, h = 0, n;
  cin >> n;
  long long int a[n];
  for (i = 0; i < n; ++i) cin >> a[i];
  s[n] = 0;
  set<long long int> b;
  set<long long int>::iterator it;
  for (i = n - 1; i >= 0; --i) {
    b.insert(a[i]);
    s[i] = b.size();
  }
  h = 0;
  for (i = 0; i < n; ++i) {
    if (!m[a[i]]) {
      h += s[i + 1];
      m[i] = 1;
    }
  }
  cout << h << endl;
  return 0;
}
