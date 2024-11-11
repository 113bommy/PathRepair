#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  if (K > N / 2) {
    while (K != N) {
      cout << "RIGHT\n";
      K++;
    }
    for (int i = S.length() - 1; i >= 0; i--) {
      if (i == 0)
        cout << "PRINT " << S[i] << "\n";
      else
        cout << "PRINT " << S[i] << "\n"
             << "LEFT\n";
    }
  } else {
    K--;
    while (K != 0) {
      cout << "LEFT\n";
      K--;
    }
    for (int i = 0; i < S.length(); i++) {
      if (i == S.length() - 1)
        cout << "PRINT " << S[i] << "\n";
      else
        cout << "PRINT " << S[i] << "\n"
             << "RIGHT\n";
    }
  }
  return 0;
}
