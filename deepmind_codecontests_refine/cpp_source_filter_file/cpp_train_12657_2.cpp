#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<string> s(n);
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
  }
  long long mini = -1;
  for (long long i = n - 1; i > 0; i--) {
    long long flag = 0;
    for (long long j = 1; j < min(s[i].size(), s[i - 1].size()); j++) {
      if (s[i - 1][j] < s[i][j]) {
        flag = 1;
        break;
      } else if (s[i - 1][j] > s[i][j]) {
        if (j == 1) {
          mini = max(mini, i);
          flag = 1;
          break;
        } else {
          s[i - 1] = s[i - 1].substr(0, j);
          flag = 1;
          break;
        }
      }
    }
    if (flag == 0) {
      s[i - 1] = s[i - 1].substr(0, min(s[i].size(), s[i - 1].size()));
    }
  }
  for (long long i = 0; i < n; i++) {
    if (i <= mini) {
      cout << "#" << endl;
    } else {
      cout << s[i] << endl;
    }
  }
}
