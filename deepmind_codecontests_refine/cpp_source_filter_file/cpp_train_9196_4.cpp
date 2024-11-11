#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5 + 7;
vector<long long> v[MX];
bool vis[2][MX], ans;
string s[2];
long long n, k;
void DFS(bool UD, long long i, long long flood) {
  if (s[UD][i] == 'X' || i <= flood || vis[UD][i]) return;
  if (i > n - k) {
    ans = 1;
    return;
  }
  vis[UD][i] = 1;
  DFS(UD, i + 1, flood + 1);
  DFS(UD, i - 1, flood + 1);
  DFS(!UD, i + k, flood + 1);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  cin >> s[0] >> s[1];
  DFS(0, 0, -1);
  if (ans)
    cout << "YES";
  else
    cout << "NO";
}
