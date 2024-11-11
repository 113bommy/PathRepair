#include <bits/stdc++.h>
using namespace std;
int N, mins = 6, i, j;
string S[1000];
int wa(string S, string R) {
  int i, H = 0;
  for (i = 0; i < 6; i++) {
    H += (S[i] != R[i]);
  }
  return (H - 1) / 2;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  for (i = 0; i < N; i++) {
    cin >> S[i];
    for (j = 0; j < i; j++) {
      mins = min(mins, wa(S[i], S[j]));
    }
  }
  cout << mins << '\n';
}
