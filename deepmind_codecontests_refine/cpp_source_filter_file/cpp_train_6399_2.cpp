#include <bits/stdc++.h>
using namespace std;
int main() {
  int X1, Y1, X2, Y2;
  int N, Ans = 0;
  cin >> X1 >> Y1;
  cin >> X2 >> Y2;
  cin >> N;
  for (int I = 0; I < N; I++) {
    int A, B, C;
    cin >> A >> B >> C;
    int64_t S1 = A * X1 + B * Y1 + C;
    int64_t S2 = A * X2 + B * Y2 + C;
    if ((S1 > 0 && S2 < 0) || (S1 < 0 && S2 > 0)) {
      Ans++;
    }
  }
  cout << Ans << endl;
  return 0;
}
