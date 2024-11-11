#include <bits/stdc++.h>
using namespace std;
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
pair<int, int> arup[100000];
pair<int, int> ardown[100000];
pair<int, int> arleft[100000];
pair<int, int> arright[100000];
map<pair<int, int>, int> MM;
int memo[15][15][15][15][15];
long long getans(int lefto, int up, int down, int left, int right) {
  if (memo[lefto][up][down][left][right] != 0)
    return memo[lefto][up][down][left][right];
  while (MM[ardown[down]] == 0) {
    down++;
  }
  while (MM[arup[up]] == 0) {
    up++;
  }
  while (MM[arleft[left]] == 0) {
    left++;
  }
  while (MM[arright[right]] == 0) {
    right++;
  }
  if (ardown[down].first < arup[up].first ||
      arright[right].second < arleft[left].second) {
    return 9223372036854775807LL;
  }
  if (lefto == 0) {
    long long x = (ardown[down].first - arup[up].first + 1) / 2;
    long long y = (arright[right].second - arleft[left].second + 1) / 2;
    x = max(x, (long long)1);
    y = max(y, (long long)1);
    return x * y;
  }
  long long ans = getans(lefto - 1, up, down, left, right);
  MM[arup[up]]--;
  ans = min(ans, getans(lefto - 1, up + 1, down, left, right));
  MM[arup[up]]++;
  MM[ardown[down]]--;
  ans = min(ans, getans(lefto - 1, up, down + 1, left, right));
  MM[ardown[down]]++;
  MM[arleft[left]]--;
  ans = min(ans, getans(lefto - 1, up, down, left + 1, right));
  MM[arleft[left]]++;
  MM[arright[right]]--;
  ans = min(ans, getans(lefto - 1, up, down, left, right + 1));
  MM[arright[right]]++;
  return memo[lefto][up][down][left][right] = ans;
}
void solve() {
  memset(memo, 0, sizeof(memo));
  ;
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < (int)(n); i++) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    arup[i].first = x1 + x2;
    ardown[i].first = x1 + x2;
    arup[i].second = y1 + y2;
    ardown[i].second = y1 + y2;
    arleft[i].first = x1 + x2;
    arright[i].first = x1 + x2;
    arleft[i].second = y1 + y2;
    arright[i].second = y1 + y2;
    MM[make_pair(x1 + x2, y1 + y2)]++;
  }
  sort(arup, arup + n);
  sort(ardown, ardown + n, greater<pair<int, int> >());
  sort(arleft, arleft + n,
       [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
  sort(arright, arright + n,
       [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });
  cout << getans(k, 0, 0, 0, 0);
}
int main() {
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  int TC = 1;
  for (int ZZ = 1; ZZ <= TC; ZZ++) {
    solve();
  }
  return 0;
}
