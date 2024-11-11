#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int ans = 0;
  int pre = 1000000;
  for (int i = 0; i < N - 1; i++) {
    int b;
    cin >> b;
    ans += min(pre, b);
    pre = b;
  }
  cout << ans << endl;
}
