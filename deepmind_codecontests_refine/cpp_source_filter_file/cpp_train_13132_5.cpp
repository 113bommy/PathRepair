#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
const double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1ll << 60;
const int mod = 1e9 + 7;
string s1, s2;
map<string, int> id;
map<int, string> name;
bool M[18][18];
int main() {
  memset((M), (false), sizeof(M));
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) cin >> s1, id[s1] = i, name[i] = s1;
  for (int i = 0; i < m; i++)
    cin >> s2 >> s2, M[id[s1]][id[s2]] = M[id[s2]][id[s1]] = true;
  pair<int, int> res = make_pair(-1, -1);
  bool ok;
  for (int i = 0, cnt = 0; i < (1 << n); i++, cnt = 0) {
    ok = true;
    for (int j = 0; j < n and ok; j++)
      if (i & (1 << j)) {
        for (int h = 0; h < n and ok; h++)
          if ((i & (1 << h)) and M[j][h]) ok = false;
        ++cnt;
      }
    if (ok and cnt > res.second) res.first = i, res.second = cnt;
  }
  vector<string> ans;
  for (int i = 0; i < n; i++)
    if (res.first & (1 << i)) ans.push_back(name[i]);
  sort((ans).begin(), (ans).end());
  printf("%d\n", (int)(ans).size());
  for (int i = 0; i < (int)(ans).size(); i++) cout << ans[i] << endl;
  return 0;
}
