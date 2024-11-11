#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, ans = 0, i = 0;
  cin >> N;
  for (; i <= N; i++) {
    ans += i;
    if (ans == N) {
      ans = -1;
      break;
    }
  }
  if (ans == -1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
