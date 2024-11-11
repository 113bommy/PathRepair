#include <bits/stdc++.h>
using namespace std;
int ar[200][200] = {0}, n, a, b, k, arr[201];
string s;
bool dp(int state, int mk) {
  if (state == 0) {
    if (mk == 0)
      return true;
    else
      return false;
  } else {
    for (int i = a; i <= b; i++) {
      if (mk - i >= 0) {
        if (ar[state - 1][mk - i] == 0)
          if (dp(state - 1, mk - i)) {
            arr[state] = i;
            return true;
          }
      }
    }
  }
  ar[state][mk] = 1;
  return false;
}
int main() {
  cin >> k >> a >> b;
  cin >> s;
  int tmp = 0;
  if (dp(k, s.size()))
    for (int i = 1; i <= k; i++) {
      for (int j = 0; j < arr[i]; j++) cout << s[tmp + j];
      tmp += arr[i];
      cout << endl;
    }
  else {
    cout << "No solution";
  }
  return 0;
}
