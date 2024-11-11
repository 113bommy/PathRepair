#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int INF = 1000000007;
int n, ans;
string s1, s2;
std::vector<vector<int> > c('z' + 1, std::vector<int>('z' + 1, INF));
template <typename T>
inline void MustDie(T tmp) {
  cout << tmp;
  exit(0);
}
void init() {
  getline(cin, s1);
  getline(cin, s2);
  if (s1.size() != s2.size()) MustDie(-1);
  for (char j = 'a'; j <= 'z'; ++j) c[j][j] = 0;
  cin >> n;
  for (int i = 0; i < (int)n; ++i) {
    char ti, tj;
    int t;
    cin >> ti >> tj >> t;
    c[ti][tj] = min(c[ti][tj], t);
  }
}
void floyd() {
  for (int k = 'a'; k <= 'z'; ++k)
    for (int i = 'a'; i <= 'z'; ++i)
      for (int j = 'a'; j <= 'z'; ++j)
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
}
int main() {
  ios_base::sync_with_stdio(0);
  init();
  floyd();
  for (int i = 0; i < (int)s1.size(); ++i)
    if (s1[i] != s2[i]) {
      int p = INF;
      char k;
      for (char j = 'a'; j <= 'z'; ++j)
        if (c[s1[i]][j] + c[s2[i]][j] <= p)
          p = c[s1[i]][j] + c[s2[i]][j], k = j;
      if (p >= INF)
        MustDie(-1);
      else
        s1[i] = k, ans += p;
    }
  cout << ans << endl << s1;
  exit(0);
}
