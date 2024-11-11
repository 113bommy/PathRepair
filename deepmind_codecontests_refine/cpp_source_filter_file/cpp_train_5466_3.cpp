#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int MOD = 1e9 + 7;
const int N = 0;
int n;
string s;
char spe;
vector<string> a[15];
int main() {
  cin >> n;
  int total = 0;
  for (auto i = 1; i <= n; i++) {
    cin >> s;
    int m = s.length();
    a[m].push_back(s);
    total += m;
  }
  for (auto i = 1; i <= 10; i++) sort(a[i].begin(), a[i].end());
  total /= (n / 2);
  cin >> spe;
  vector<string> ans;
  if (total % 2 == 0) {
    int m = a[total / 2].size();
    for (int i = 0; i < m; i += 2)
      ans.push_back(a[total / 2][i] + spe + a[total / 2][i + 1]);
  }
  for (auto i = 1; i <= total / 2; i++) {
    int m = a[i].size();
    for (auto j = 0; j < m; j++)
      ans.push_back(min(a[i][j] + spe + a[total - i][j],
                        a[total - i][j] + spe + a[i][j]));
  }
  sort(ans.begin(), ans.end());
  for (auto cs : ans) cout << cs << '\n';
}
