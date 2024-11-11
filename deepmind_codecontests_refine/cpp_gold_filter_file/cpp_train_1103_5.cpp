#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ;
  int k;
  cin >> k;
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  int sum = 0;
  for (int i = 0; i < s.length(); i++) {
    int a = s[i] - '0';
    sum += a;
  }
  int ans = 0;
  if (sum >= k)
    cout << "0"
         << "\n";
  else {
    sum = k - sum;
    for (int i = 0; i < s.length(); i++) {
      sum = sum - ('9' - s[i]);
      ans++;
      if (sum <= 0) break;
    }
    cout << ans << "\n";
  }
}
