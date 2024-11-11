#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, ans = 1;
  cin >> N;
  while(N > 0) {
    ans *= N;
    ans %= 1000000007;
    N--;
  }
  cout << ans;
}