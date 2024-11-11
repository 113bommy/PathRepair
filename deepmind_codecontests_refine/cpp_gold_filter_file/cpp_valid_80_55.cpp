#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  string s;
  for (int t = (int)(0); t < (int)((T)); t++) {
    int N;
    cin >> N >> s;
    int zeropos = -1;
    for (int i = (int)(0); i < (int)((N)); i++)
      if (s[i] == '0') {
        zeropos = i;
        break;
      }
    if (zeropos == -1) {
      cout << "1 " << N - 1 << " 2 " << N << "\n";
    } else if (zeropos < N / 2) {
      cout << zeropos + 1 << " " << N << " " << zeropos + 2 << " " << N << "\n";
    } else {
      cout << "1 " << zeropos + 1 << " 1 " << zeropos << "\n";
    }
  }
}
