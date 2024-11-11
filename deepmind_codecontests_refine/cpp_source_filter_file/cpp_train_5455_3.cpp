#include <bits/stdc++.h>
using namespace std;
long long CalcV(long long N, long long S) {
  long long V = 0, C = 0;
  for (int i = 1; i <= N; i++) {
    int c = ((i - 1) / S) + (N - i - 1) / S;
    if (c == C)
      V++;
    else if (c > C)
      V = 1, C = c;
  }
  return V;
}
int main() {
  long long N, M, S, Ns, Ms;
  cin >> N >> M >> S;
  Ns = CalcV(N, S), Ms = CalcV(M, S);
  cout << (Ns * Ms) << endl;
}
