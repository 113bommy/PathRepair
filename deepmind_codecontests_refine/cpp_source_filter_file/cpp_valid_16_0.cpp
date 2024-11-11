#include <bits/stdc++.h>
using namespace std;
int inf = 1e9 + 7, MOD = 1e9 + 7;
int ar[41];
int main() {
  std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    sort(t.begin(), t.end());
    int c = 0;
    for (int i = 0; i < s.length(); i++)
      if (t[i] == s[i]) c++;
    cout << c << "\n";
  }
}
