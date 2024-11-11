#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int mod = 1e9 + 7;
char s[maxn];
int main() {
  int n;
  cin >> n;
  cin >> s;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] > s[i + 1]) {
      cout << "YES\n";
      cout << i << " " << i + 1;
      return 0;
    }
  }
  cout << "NO";
}
