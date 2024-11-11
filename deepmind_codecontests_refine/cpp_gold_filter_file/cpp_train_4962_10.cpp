#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, A, B, C, T;
  cin >> N >> A >> B >> C >> T;
  long long if0 = 0, ifT = 0;
  for (int i = 0; i < N; ++i) {
    long long k;
    cin >> k;
    if0 += A;
    ifT += A + (C - B) * (T - k);
  }
  if (if0 > ifT)
    cout << if0 << endl;
  else
    cout << ifT << endl;
  return 0;
}
