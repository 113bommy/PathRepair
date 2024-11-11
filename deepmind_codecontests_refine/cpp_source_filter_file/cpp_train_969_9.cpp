#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
  cin >> N;
  int i, num, minn, maxn, ans = 0;
  cin >> minn;
  minn = maxn;
  for (i = 1; i < N; ++i) {
    cin >> num;
    if (num > maxn) {
      ++ans;
      maxn = num;
    }
    if (num < minn) {
      ++ans;
      minn = num;
    }
  }
  cout << ans;
  return 0;
}
