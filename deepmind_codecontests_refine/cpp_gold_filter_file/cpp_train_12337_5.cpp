#include <bits/stdc++.h>
using namespace std;
int main() {
  char A, B, a[26];
  string S;
  int j, k, ii;
  cin >> j >> k >> S;
  ii = S.size();
  for (int i = 0; i < 26; i++) a[i] = i + 'a';
  while (k--) {
    cin >> A >> B;
    for (int jj = 0; jj < 26; jj++) {
      if (a[jj] == A)
        a[jj] = B;
      else if (a[jj] == B)
        a[jj] = A;
    }
  }
  for (int i = 0; i < ii; i++) S[i] = a[S[i] - 'a'];
  cout << S << endl;
  return 0;
}
