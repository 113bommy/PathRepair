#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long a[11];
  for (int i = 1; i < 10; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] - '1' + 1 < a[s[i] - '1' + 1]) {
      s[i] = a[s[i] - '1' + 1] + '1' - 1;
      for (int j = i + 1; j < s.size(); j++) {
        if (s[j] - '1' + 1 <= a[s[j] - '1' + 1])
          s[j] = a[s[j] - '1' + 1] + '1' - 1;
        else
          break;
      }
      break;
    }
  }
  cout << s;
  return 0;
}
