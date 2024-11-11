#include <bits/stdc++.h>
using namespace std;
int a[100002];
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long int XpowerY(long long int x, long long int y, long long int m) {
  long long int ans = 1;
  x = x % m;
  while (y > 0) {
    if (y % 2 == 1) ans = (ans * x) % m;
    x = ((x % m) * (x % m)) % m;
    y = y >> 1;
  }
  return ans % m;
}
int main() {
  int m1 = 1e8, n, m;
  cin >> n >> m;
  string s1, s2;
  cin >> s1 >> s2;
  vector<int> ans;
  for (int i = 0; i + n < m; i++) {
    vector<int> wr;
    for (int j = 0; j < n; j++) {
      if (s1[j] != s2[i + j]) wr.push_back(j + 1);
    }
    if (wr.size() < m1) {
      m1 = wr.size();
      ans = wr;
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
