#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  long long n;
  cin >> t;
  vector<int> v;
  while (t--) {
    cin >> n;
    v.clear();
    if (n % 4) {
      cout << "NO" << endl;
      continue;
    } else {
      cout << "YES" << endl;
      for (int i = 2; i <= n; i += 2) v.push_back(i);
      for (int i = 1; i < n; i += 2) v.push_back(i);
      v.push_back(n - 1 + n / 2);
      for (__typeof(n) i = 0; i < (n); i++)
        cout << v[i] << (i < (n - 1) ? " " : "\n");
    }
  }
  return 0;
}
