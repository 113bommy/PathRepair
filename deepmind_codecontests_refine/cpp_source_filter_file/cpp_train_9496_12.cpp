#include <bits/stdc++.h>
using namespace std;
const int N = 110;
map<string, int> mp, mp2;
string cur[N];
void sol1(int n) {
  string ans;
  for (int i = 1; i <= n; ++i) {
    cout << "? " << i << ' ' << i << '\n';
    fflush(stdout);
    char x;
    cin >> x;
    ans.push_back(x);
  }
  cout << "! " << ans << '\n';
}
void sol2(int n) {
  string ans = string(n, 'a');
  cout << "? 2 " << n << '\n';
  fflush(stdout);
  for (int i = 0; 2 * i < (n) * (n - 1); ++i) {
    string x;
    cin >> x;
    sort(x.begin(), x.end());
    mp[x]++;
  }
  cout << "? 1 " << n << '\n';
  fflush(stdout);
  for (int i = 0; 2 * i < n * (n + 1); ++i) {
    string x;
    cin >> x;
    sort(x.begin(), x.end());
    if (mp[x] == 0)
      cur[x.size()] = x;
    else
      mp[x]--;
  }
  int sumLetters = 0;
  for (int i = 1; i <= n; ++i) {
    int curSum = 0;
    for (auto j : cur[i]) curSum += j;
    int lt = curSum - sumLetters;
    ans[i - 1] = char(lt);
    sumLetters = curSum;
  }
  cout << "! " << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio();
  cin.tie(0);
  int n;
  cin >> n;
  if (n > 3)
    sol1(n);
  else
    sol2(n);
}
