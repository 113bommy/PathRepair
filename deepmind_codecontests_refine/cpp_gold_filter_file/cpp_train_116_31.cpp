#include <bits/stdc++.h>
using namespace std;
const int md = (int)1e9 + 7;
const int siz = 300005;
long long arr[siz];
long long n, m, k, l;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  cin >> s;
  map<char, int> m, mi;
  for (int i = n - 1; i >= 0; i--) {
    if (!m[s[i]]) {
      m[s[i]] = i + 1;
    }
    if (!mi[s[i]] || mi[s[i]] > i + 1) {
      mi[s[i]] = i + 1;
    }
  }
  int sm = 0;
  for (auto xx : m) {
    int x1 = xx.first, x = xx.second;
    for (auto yy : mi) {
      int y1 = yy.first, y = yy.second;
      if (y1 > x1 && y < x) {
        cout << "YES" << '\n' << y << " " << x;
        return 0;
      }
    }
  }
  cout << "NO";
}
