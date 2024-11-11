#include <bits/stdc++.h>
using namespace std;
inline void boost() {
  ios_base::sync_with_stdio();
  cin.tie(0);
}
const long long MAX = 1e5 + 111;
const long long mod = 1e9 + 7;
map<string, int> maap;
vector<int> g[MAX];
int main() {
  boost();
  int n;
  bool ans = false;
  cin >> n;
  string a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i][0] == 'O' && a[i][1] == 'O') {
      a[i].erase(0, 2);
      a[i].insert(0, "++");
      ans = true;
      break;
    }
    if (a[i][3] == 'O' && a[i][4] == 'O') {
      a[i].erase(3, 4);
      a[i].insert(3, "++");
      ans = true;
      break;
    }
  }
  if (ans == true) {
    cout << "YES";
    for (int i = 1; i <= n; i++) {
      cout << a[i] << "\n";
    }
  } else {
    cout << "NO";
  }
  exit(0);
}
