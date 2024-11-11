#include <bits/stdc++.h>
using namespace std;
long long int n, m, q, f = 0;
vector<long long int> v[100005], c(100005, 0), s(100005, 0), a(100005, 0),
    b(100005, 0);
int main() {
  cin >> n;
  for (long long int i = 0; i < n - 1; i++) {
    cin >> a[i] >> b[i];
  }
  for (long long int i = 0; i < n; i++) {
    cin >> s[i];
  }
  long long int ans = 0;
  for (long long int i = 0; i < n - 1; i++) {
    if (s[a[i]] != s[b[i]]) {
      ans++;
      c[a[i]]++;
      c[b[i]]++;
    }
  }
  for (long long int i = 0; i < n; i++) {
    if (ans == c[i]) {
      cout << "YES\n";
      cout << i << endl;
      exit(0);
    }
  }
  cout << "NO\n";
}
