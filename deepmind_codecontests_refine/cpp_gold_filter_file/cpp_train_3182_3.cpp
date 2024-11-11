#include <bits/stdc++.h>
const long long int inf = LLONG_MAX;
using namespace std;
set<char> my;
string s;
int n, a[1005];
int main() {
  int f = 1;
  cin >> n;
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  string l("aeiouy");
  cin.get();
  for (long long int j = 1; j <= n; j++) {
    int c = 0;
    getline(cin, s);
    int t = s.length() - 1;
    for (long long int i = 0; i <= t; i++) {
      for (long long int k = 0; k <= 5; k++) {
        if (s[i] == l[k]) {
          c++;
          break;
        }
      }
    }
    if (c != a[j] && f != -1) f = -1;
  }
  if (f == -1)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
