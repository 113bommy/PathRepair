#include <bits/stdc++.h>
using namespace std;
int sum, res;
vector<int> num, ans;
void Input() {
  long long n;
  cin >> n;
  while (n > 0) {
    num.push_back(n % 10);
    sum += n % 10;
    n /= 10;
  }
}
void Solve() {
  res = sum;
  ans = num;
  for (int i = 1; i < (int)num.size(); i++) {
    if (num[i] == 0) continue;
    sum--;
    num[i]--;
    for (int j = 0; j < i; j++) {
      sum += 9 - num[j];
      num[j] = 9;
    }
    if (sum > res) {
      res = sum;
      ans = num;
    }
  }
  reverse(ans.begin(), ans.end());
  int i = 0;
  while (ans[i] == 0) i++;
  for (; i < (int)ans.size(); i++) cout << ans[i];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Input();
  Solve();
}
