#include <bits/stdc++.h>
using namespace std;
vector<long long int> num;
void solve(int i, long long int n) {
  if (i > 10) {
    return;
  }
  num.push_back(n);
  solve(i + 1, (n * 10) + 4);
  solve(i + 1, (n * 10) + 7);
}
void hehe() {
  solve(0, 0);
  sort(num.begin(), num.end());
  long long int a, b;
  cin >> a >> b;
  int l = num.size();
  vector<long long int> count(l, 0);
  long long int ans = 0;
  for (int i = 1; i < num.size(); i++) {
    if (num[i] < a || num[i - 1] >= b) continue;
    long long int left = max(num[i - 1], a - 1);
    long long int right = min(b, num[i]);
    ans += (right - left) * (num[i]);
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    hehe();
  }
  return 0;
}
