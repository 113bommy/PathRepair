#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string S;
    cin >> S;
    int size = S.size();
    int maxm = 1, cnt = 0, i;
    for (i = 0; i < size; i++) {
      if (S[i] == 'L')
        cnt++;
      else {
        maxm = max(maxm, cnt);
        cnt = 0;
      }
    }
    maxm = max(maxm, cnt);
    cout << maxm + 1 << endl;
  }
}
