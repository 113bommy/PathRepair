#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  string s;
  cin >> s;
  int n = s.size();
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (s[i] - '0');
  }
  int rem = (k - sum);
  if (sum >= k) {
    cout << "0" << endl;
    return 0;
  } else {
    int cnt = 0;
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
      int tmp = 9 - (s[i] - '0');
      rem -= tmp;
      cnt++;
      if (rem < 0) {
        cout << cnt << endl;
        return 0;
      }
      if (rem == 0) {
        cout << cnt << endl;
        return 0;
      }
    }
  }
  return 0;
}
