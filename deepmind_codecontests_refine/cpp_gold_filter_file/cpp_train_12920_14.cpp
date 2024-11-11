#include <bits/stdc++.h>
using namespace std;
int T;
string S;
int ca(char c) {
  if ('0' <= c && c <= '9') return 0;
  if ('A' <= c && c <= 'Z') return 1;
  if ('a' <= c && c <= 'z') return 2;
}
int main() {
  cin >> T;
  while (T--) {
    cin >> S;
    int cs[] = {0, 0, 0};
    for (int i = 0; i < S.size(); i++) cs[ca(S[i])]++;
    int Ans = (bool)cs[0] + (bool)cs[1] + (bool)cs[2];
    if (Ans == 2) {
      for (int i = 0; i < S.size(); i++)
        if (cs[ca(S[i])] >= 2) {
          S[i] = (!cs[0] ? '1' : (!cs[1] ? 'A' : 'a'));
          break;
        }
    }
    if (Ans == 1) {
      S[0] = (!cs[0] ? '1' : (!cs[1] ? 'A' : 'a'));
      cs[ca(S[0])]++;
      S[1] = (!cs[0] ? '1' : (!cs[1] ? 'A' : 'a'));
    }
    cout << S << endl;
  }
}
