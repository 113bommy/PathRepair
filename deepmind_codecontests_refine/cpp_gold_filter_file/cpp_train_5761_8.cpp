#include <bits/stdc++.h>
using namespace std;
bool mat[2001][2001];
string s;
void mark(int l, int r) {
  int sz = s.size();
  while (l >= 0 and r < sz and s[r] == s[l]) {
    mat[l][r] = 1;
    l--;
    r++;
  }
}
vector<int> x, y;
int main() {
  cin >> s;
  int sz = s.size();
  memset(mat, 0, sizeof mat);
  for (int i = 0; i < sz; i++) {
    mark(i, i);
    mark(i - 1, i);
    mark(i, i + 1);
  }
  for (int i = 0; i < sz; i++)
    for (int j = 0; j < sz; j++)
      if (mat[i][j]) x.push_back(i), y.push_back(j);
  long long ans = 0;
  for (int i = 0; i < x.size(); i++) {
    int u = upper_bound(x.begin(), x.end(), y[i]) - x.begin();
    ans += x.size() - u;
  }
  cout << ans << endl;
}
