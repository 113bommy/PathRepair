#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n;
  cin >> n >> s;
  for (int i = 0; i + 1 < n; i++) {
    if (s[i] > s[i + 1]) {
      cout << "YES" << endl << i + 1 << " " << i + 2;
      return 0;
    }
  }
  cout << "NO";
}
