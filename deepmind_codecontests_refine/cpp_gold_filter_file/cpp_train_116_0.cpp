#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string a = s;
  sort(a.begin(), a.end());
  if (a == s) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  for (int i = n - 2; i >= 0; i--) {
    if (s[i] > s[i + 1]) {
      cout << i + 1 << " " << i + 2 << endl;
      return 0;
    }
  }
}
