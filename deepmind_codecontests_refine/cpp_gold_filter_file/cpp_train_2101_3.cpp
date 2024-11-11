#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  string s1, s2;
  while (T--) {
    cin >> s1 >> s2;
    int count = 0, answer = 0;
    for (int i = s2.size() - 1; i >= 0; i--) {
      if (s2[i] == '0')
        count++;
      else
        break;
    }
    for (int i = s1.size() - count - 1; i >= 0; i--) {
      if (s1[i] == '0')
        answer++;
      else
        break;
    }
    cout << answer << endl;
  }
  return 0;
}
