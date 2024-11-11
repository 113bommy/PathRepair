#include <bits/stdc++.h>
using namespace std;
vector<pair<char, pair<int, int> > > spiders;
string s;
int n, m, k;
int a[2002][2002];
int ans[2002];
void nextT(int T) {}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++)
      if (s[j] != '.') {
        if (s[j] == 'R') {
          if (i + j < m) ans[i + j]++;
        } else if (s[j] == 'L') {
          if (j - i >= 0) ans[j - i]++;
        } else if (s[j] == 'U' && i != 1)
          ans[j]++;
      }
  }
  for (int i = 0; i < m; i++) cout << ans[i] << " ";
  cout << endl;
}
