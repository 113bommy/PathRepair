#include <bits/stdc++.h>
using namespace std;
int n;
int a[100009];
bool vis[100009];
string s;
int main() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) cin >> a[i];
  int i = 0;
  while (true) {
    if (vis[i] == true) {
      cout << "INFINITE";
      return 0;
    }
    vis[i] = true;
    if (s[i] == '>') {
      if (a[i] >= n - i) {
        cout << "FINITE";
        return 0;
      } else {
        i = i + a[i];
      }
    } else {
      if (a[i] >= i) {
        cout << "FINITE";
        return 0;
      } else {
        i = i - a[i];
      }
    }
  }
}
