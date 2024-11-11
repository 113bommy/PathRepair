#include <bits/stdc++.h>
using namespace std;
const long long int k = 1000 * 1000 * 1000 + 7;
int h[2002];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int k;
  cin >> k;
  string s;
  cin >> s;
  int y = s.length();
  int h[9] = {0};
  int sum = 0;
  int cnt = 0;
  std::vector<int> v;
  for (int i = 0; i < y; i++) {
    sum += s[i] - 48;
    h[s[i] - 48]++;
  }
  if (sum >= k) {
    cout << 0;
    return 0;
  }
  sort(s.begin(), s.end());
  int d = k - sum, temp = 0;
  for (int i = 0; i < y; ++i) {
    temp = 9 - (s[i] - 48);
    s[i] += temp;
    cnt++;
    d -= temp;
    if (d <= 0) break;
  }
  cout << cnt;
  return 0;
}
