#include <bits/stdc++.h>
using namespace std;
int appear[10];
int main(void) {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    memset(appear, 0, sizeof(appear));
    string s;
    cin >> s;
    if (s.size() == 2) {
      cout << 0 << '\n';
      continue;
    }
    int answer = s.size() - 2;
    int part = 0;
    for (int i = 0; i <= 9; i++) {
      for (int j = 0; j <= 9; j++) {
        if (i == j) continue;
        int recur = 0;
        for (int k = 0; k < s.size(); k++) {
          if (recur == 0 || recur % 2 == 0) {
            if (s[k] - '0' == i) recur++;
          } else {
            if (s[k] - '0' == j) recur++;
          }
        }
        if (recur % 2 == 1) recur--;
        part = max(part, recur);
      }
    }
    if (part != 0) {
      int p = s.size() - part;
      answer = min(answer, p);
    }
    for (int i = 0; i < s.size(); i++) appear[s[i] - '0']++;
    int num = 0;
    for (int i = 0; i < 10; i++) num = max(num, appear[i]);
    num = s.size() - num;
    answer = min(num, answer);
    cout << answer << '\n';
  }
  return 0;
}
