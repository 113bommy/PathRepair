#include <bits/stdc++.h>
using namespace std;

int func(int A, int B, int C) {
  if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) return 0;
  if (A == B && A == C) return -1;
  return func((B + C) / 2, (A + C) / 2, (A + B) / 2) + 1;
}

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  int ans = func(A, B, C);
  cout << ans << endl;
}