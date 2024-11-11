#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '#') {
      int j;
      for (j = i; j < n; j++)
        if (s[j] != '#') break;
      if (j - i + 1 > k) return cout << "NO", 0;
      i = j;
    }
  }
  cout << "YES";
}
