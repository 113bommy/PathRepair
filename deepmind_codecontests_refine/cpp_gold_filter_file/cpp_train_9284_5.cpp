#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int n, a, b, tot;
string s;
int w[maxn];
bool cmp(int x, int y) { return x > y; }
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  while (n--) {
    cin >> a >> b;
    cin >> s;
    int k = 0;
    tot = 0;
    memset(w, 0, sizeof(w));
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'X') {
        if (k >= b) w[++tot] = k;
        k = 0;
        continue;
      }
      k++;
      if (i == s.length() - 1)
        if (k >= b) w[++tot] = k;
    }
    sort(w + 1, w + tot + 1, cmp);
    bool flag = 0;
    for (int i = 1; i <= tot; i++)
      if (w[i] < a) {
        flag = 1;
        break;
      }
    if (flag || w[2] >= b * 2) {
      cout << "NO\n";
      continue;
    }
    if (w[1] < b * 2) {
      int sum = 0;
      for (int i = 1; i <= tot && w[i] >= a; i++) sum++;
      if (sum % 2 == 0)
        cout << "NO\n";
      else
        cout << "YES\n";
    }
    if (w[1] >= b * 2) {
      int sum = 0;
      for (int i = 2; i <= tot && w[i] >= a; i++) sum++;
      if (sum % 2 == 1)
        if (w[1] >= a * 2 && w[1] < a + b * 3 - 1)
          cout << "YES\n";
        else
          cout << "NO\n";
      if (sum % 2 == 0)
        if (w[1] <= a + b * 2 - 2 || w[1] >= a * 3 && w[1] < a + b * 4 - 1)
          cout << "YES\n";
        else
          cout << "NO\n";
    }
  }
  return 0;
}
