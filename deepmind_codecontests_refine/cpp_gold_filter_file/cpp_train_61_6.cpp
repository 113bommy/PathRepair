#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> s >> n;
  vector<string> a(n);
  for (string& i : a) cin >> i;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      string t = a[i] + a[j];
      if (t.find(s) != -1) return !(cout << "YES");
    }
  }
  cout << "NO";
  return 0;
}
