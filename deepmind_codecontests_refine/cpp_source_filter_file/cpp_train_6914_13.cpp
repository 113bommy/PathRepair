#include <bits/stdc++.h>
using namespace std;
const int MAX = 333;
int N;
int a[MAX];
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> a[i];
  for (;;) {
    bool flag = false;
    for (int i = 1; i <= N; i++) {
      if (a[i]) {
        cout << "P";
        a[i]--;
        flag = true;
      }
      if (i < N) cout << "R";
    }
    cout << "L";
    for (int i = N - 1; i >= 1; i--) {
      if (a[i]) {
        cout << "P";
        a[i]--;
        flag = true;
      }
      if (i > 1) cout << "L";
    }
    if (!flag) break;
  }
  cout << endl;
  return 0;
}
