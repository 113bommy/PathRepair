#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, C0, C1, H;
    cin >> N >> C0 >> C1 >> H;
    string S;
    cin >> S;
    int Z = 0, O = 0;
    for (int i = 0; i < S.length(); i++) {
      if (S[i] == '0')
        Z++;
      else
        O++;
    }
    int Ans = 0;
    if (C0 == C1) {
      Ans += N * C0;
    } else {
      int TAns = Z * C0 + O * C1;
      int TAns2 = 0;
      if (C0 > C1) {
        TAns2 = Z * H;
        TAns2 += N * C1;
      } else {
        TAns2 = O * H;
        TAns2 += N * C0;
      }
      Ans = min(TAns, TAns2);
    }
    cout << Ans << endl;
  }
  return 0;
}
